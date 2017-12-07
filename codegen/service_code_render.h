/*
Tencent is pleased to support the open source community by making
PhxRPC available.
Copyright (C) 2016 THL A29 Limited, a Tencent company.
All rights reserved.

Licensed under the BSD 3-Clause License (the "License"); you may
not use this file except in compliance with the License. You may
obtain a copy of the License at

https://opensource.org/licenses/BSD-3-Clause

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" basis,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
implied. See the License for the specific language governing
permissions and limitations under the License.

See the AUTHORS file for names of contributors.
*/

#pragma once

#include <cstdio>
#include <map>
#include <string>
#include <vector>


namespace phxrpc {


class NameRender;
class SyntaxTree;
class SyntaxFunc;
typedef std::vector<SyntaxFunc> SyntaxFuncVector;

class ServiceCodeRender {
  public:
    ServiceCodeRender(NameRender &name_render);
    virtual ~ServiceCodeRender();

    virtual void GenerateServiceHpp(SyntaxTree *stree,
                                    const SyntaxFuncVector &mqtt_funcs,
                                    FILE *write);

    virtual void GenerateServiceCpp(SyntaxTree *stree,
                                    const SyntaxFuncVector &mqtt_funcs,
                                    FILE *write);

    virtual void GenerateServiceImplHpp(SyntaxTree *stree,
                                        const SyntaxFuncVector &mqtt_funcs,
                                        FILE *write, const bool is_uthread_mode);

    virtual void GenerateServiceImplCpp(SyntaxTree *stree,
                                        const SyntaxFuncVector &mqtt_funcs,
                                        FILE *write, const bool is_uthread_mode);

    virtual void GenerateDispatcherHpp(SyntaxTree *stree, FILE *write);

    virtual void GenerateDispatcherCpp(SyntaxTree *stree,
                                       const SyntaxFuncVector &mqtt_funcs,
                                       FILE *write);

  protected:
    struct FunctionItem {
        std::string protocol_name;
        std::string function_name;
    };

    virtual void GetServiceFuncDeclaration(SyntaxTree *stree,
            const SyntaxFunc *const func, int is_header, int is_impl,
            int need_param_name, std::string *result);

    virtual void GenerateMqttDispatcherFunc(SyntaxTree *stree,
                                            const SyntaxFunc *const func,
                                            FILE *write);

    virtual void GenerateDispatcherFunc(SyntaxTree *stree,
                                        const SyntaxFunc *const func,
                                        FILE *write);

    virtual void GenerateMqttFuncMap(SyntaxTree *stree,
                                     const std::vector<FunctionItem> functions,
                                     FILE *write);

    virtual void GenerateURIFuncMap(SyntaxTree *stree, FILE *write);

    NameRender &name_render_;
};


}

