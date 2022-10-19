#include <iostream>

#define long long long
#define M 100100
#define pr 1000000007

using namespace std;

long p[M],w[M],s=0;

long anc(long x){
    long a;
    if (p[x]==x)
    return x;
    a=anc(p[x]);
    w[x]+=w[p[x]];
    w[x]%=pr;
    p[x]=a;
    return a;
}

void init(void){
    for (long i=0; i<M; ++i){
        p[i]=i;
        w[i]=0;
    }
}

void req(long o){
    long k,v,x,a;
    cin>>k;
    for (long i=0; i<k; ++i){
        cin>>v>>x;
        a=anc(v);
        p[a]=o;
        w[a]=(w[v]+x)%pr;
        s+=w[a];
        s%=pr;
    }
}


int main()
{
    long n;
    init();
    cin>>n;
    for (long i=1; i<=n; ++i)
    req(i);

    s%=pr;
    if (s<0)
    s+=pr;
    cout<<s;

    return 0;
}