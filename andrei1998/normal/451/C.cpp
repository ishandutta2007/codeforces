#include <iostream>
#include <algorithm>
#include <cmath>

#define lint long long int
using namespace std;

bool ok(lint a,lint b,lint c,lint k)
{
    lint maxim=max(max(a,b),c);
    lint ramas=k-(3*maxim-a-b-c);

    if(ramas<0)
        return 0;
    else if(ramas%3!=0)
        return 0;
    return 1;
}

bool prepare1(lint &a,lint &b,lint &c,lint d1,lint d2,lint k)
{
    if((k-d1-d2)%3!=0)
        return 0;
    b=(k-d1-d2)/3;
    a=b+d1;
    c=b+d2;

    if(a<0 || b<0 || c<0)
        return 0;
    if(a>=b && b<=c)
        return 1;
    return 0;
}

bool prepare2(lint &a,lint &b,lint &c,lint d1,lint d2,lint k)
{
    if((k-d1+d2)%3!=0)
        return 0;
    b=(k-d1+d2)/3;
    a=b+d1;
    c=b-d2;

    if(a<0 || b<0 || c<0)
        return 0;
    if(a>=b && b>=c)
        return 1;
    return 0;
}

bool prepare3(lint &a,lint &b,lint &c,lint d1,lint d2,lint k)
{
    if((k+d1+d2)%3!=0)
        return 0;
    b=(k+d1+d2)/3;
    a=b-d1;
    c=b-d2;

    if(a<0 || b<0 || c<0)
        return 0;
    if(a<=b && b>=c)
        return 1;
    return 0;
}

bool prepare4(lint &a,lint &b,lint &c,lint d1,lint d2,lint k)
{
    if((k+d1-d2)%3!=0)
        return 0;
    b=(k+d1-d2)/3;
    a=b-d1;
    c=b+d2;

    if(a<0 || b<0 || c<0)
        return 0;
    if(a<=b && b<=c)
        return 1;
    return 0;
}

int main()
{
    int t=0;
    cin>>t;

    while(t--){
        lint n,k,d1,d2;
        cin>>n>>k>>d1>>d2;

        lint a,b,c;

        if(prepare1(a,b,c,d1,d2,k))
        if(ok(a,b,c,n-k)){
            cout<<"yes\n";
            continue;
        }

        if(prepare2(a,b,c,d1,d2,k))
        if(ok(a,b,c,n-k)){
            cout<<"yes\n";
            continue;
        }

        if(prepare3(a,b,c,d1,d2,k))
        if(ok(a,b,c,n-k)){
            cout<<"yes\n";
            continue;
        }

        if(prepare4(a,b,c,d1,d2,k))
        if(ok(a,b,c,n-k)){
            cout<<"yes\n";
            continue;
        }

        cout<<"no\n";
    }

    return 0;
}