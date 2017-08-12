#ifndef NET_QML_VALUE_TYPE_H
#define NET_QML_VALUE_TYPE_H

#include "qtnetcoreqml_global.h"
#include "qobject.h"
#include "net_type_info.h"

template <int N>
class GoValueType : public GoValue
{
public:

    GoValueType()
        : GoValue(NULL, typeInfo, 0) {};

    static void init(NetTypeInfo *info)
    {
        typeInfo = info;
        static_cast<QMetaObject &>(staticMetaObject) = *metaObjectFor(typeInfo);
    };

    static NetTypeInfo *typeInfo;
    static QMetaObject staticMetaObject;
};

#endif // NET_QML_VALUE_TYPE_H