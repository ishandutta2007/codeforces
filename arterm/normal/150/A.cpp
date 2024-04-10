#include <iostream>

#define long long long

using namespace std;


int main()
{
    long q,a[100],t=0,b;

    cin>>q;
    b=q;

    for(long i=2; i*i<=q; ++i)
    if (q%i==0)
    while (q%i==0){
        a[t++]=i;
        q/=i;
    }

    if (q>1)
    a[t++]=q;

    if (t==1 || b==1){
        cout<<1<<"\n"<<0;
    }

    if (t==2){
        cout<<2;
    }

    if (t>2){
        cout<<1<<"\n";
        cout<<a[1]*a[0];
    }

    return 0;
}