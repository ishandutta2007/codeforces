#include <iostream>

#define long long long
#define p 1000000007ll
#define M 200200

using namespace std;

long f[M],r[M];

void pre(void){
    f[0]=r[0]=1;
    f[1]=r[1]=1;
    for (int i=2; i<M; ++i){
        f[i]=(f[i-1]*i)%p;
        r[i]=(-p/i*r[p%i])%p;
    }
    for (int i=2; i<M; ++i)
    r[i]=(r[i-1]*r[i])%p;
}

long cnk(long n, long k){
    if (k<0 || n<k)
    return 0;
    long b=(f[n]*r[k])%p;
    return (b*r[n-k])%p;
}

long gen(int n, int m, bool g){
    if (n<0 || m<0)
    return 0;
    if (n+m==2){
        if (g)
        return n==2;
        if (m==0)
        return 0;
        if (m==1)
        return 2;
        return 1;
    }
    if (g)
    return gen(n-1,m,0);
    else
    return (cnk(n+m-1,m-1)+gen(n-1,m,1))%p;
}

int main()
{
    int n,m,g;
    pre();
    cin>>n>>m>>g;
    if (n+m==1){
        cout<<(m==g)<<"\n";
        return 0;
    }
    cout<<(p+gen(n,m,g))%p<<"\n";
    return 0;
}