#include <bits/stdc++.h>

using namespace std;

const long long mod=998244353;

long long fpow(long long b,long long e)
{
    long long res=1;
    b%=mod;
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
    long long n,m,l,r;
    scanf("%I64d%I64d%I64d%I64d",&n,&m,&l,&r);
    if((n&1)&&(m&1)) printf("%I64d\n",fpow(r-l+1,m*n));
    else
    {
        long long a=(r-l+1)/2;
        long long b=(r-l+1-a);
        long long res=(fpow(abs(a-b),n*m)+fpow(a+b,n*m))%mod;
        res=(res*499122177ll)%mod;
        printf("%I64d\n",res);
    }
    return 0;
}