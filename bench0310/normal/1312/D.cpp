#include <bits/stdc++.h>

using namespace std;

const long long mod=998244353;

long long fpow(long long b,long long e)
{
    long long res=1;
    while(e)
    {
        if(e&1) res=(res*b)%mod;
        b=(b*b)%mod;
        e/=2;
    }
    return res;
}

int main()
{
    long long n,m;
    scanf("%I64d%I64d",&n,&m);
    if(n-1>m)
    {
        printf("0\n");
        return 0;
    }
    vector<long long> f(m+1,1);
    for(long long i=1;i<=m;i++) f[i]=(f[i-1]*i)%mod;
    long long res=f[m];
    res=(res*fpow(f[n-1],mod-2))%mod;
    res=(res*fpow(f[m-(n-1)],mod-2))%mod;
    res=(res*(n-2))%mod;
    long long p=1;
    for(long long i=0;i<n-3;i++) p=(2ll*p)%mod;
    res=(res*p)%mod;
    printf("%I64d\n",res);
    return 0;
}