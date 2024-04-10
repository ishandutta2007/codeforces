#include <iostream>

#define M 100100
#define long long long
#define INF 2000000000000LL

using namespace std;

long n,q,v[M],c[M],x[M],fm=1,sm=2;

void read(void){
    cin>>n>>q;
    for (long i=0; i<n; ++i)
    cin>>v[i];
    for (long i=0; i<n; ++i)
    cin>>c[i];
}

void ini(void){
    fm=1,sm=2;
    for (long i=0; i<M; ++i)
    x[i]=-INF;
}

long ans(long p){
    if (fm!=p)
    return x[fm];
    return x[sm];
}

void upd(long p, long nw) {
    x[p]=nw;
    if (p!=fm && x[p]>x[sm])
    sm=p;

    if (x[sm]>x[fm])
    swap(sm,fm);
}

void que(void){
    long a,b,x1,x2,x3,col,an,tem;
    cin>>a>>b;
    ini();
    for (long i=0; i<n; ++i){
        x1=b*v[i];
        col=c[i];
        x2=x[col]+a*v[i];
        x3=ans(col);
        x3=x3+b*v[i];
        tem=x[col];
        tem=max(tem,x1);
        tem=max(tem,x2);
        tem=max(tem,x3);
        if (tem>x[col])
        upd(col,tem);
    }

    an=x[fm];
    if (an<0)
    an=0;

    cout<<an<<"\n";

}

int main()
{
    ios_base::sync_with_stdio(0);
    read();
    for (long i=0; i<q; ++i)
    que();
    return 0;
}