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
    const int N=1000;
    vector<long long> f(N+1,1);
    for(long long i=1;i<=N;i++) f[i]=(f[i-1]*i)%mod;
    vector<long long> finv(N+1,0);
    finv[N]=fpow(f[N],mod-2);
    for(long long i=N-1;i>=0;i--) finv[i]=(finv[i+1]*(i+1))%mod;
    long long d;
    scanf("%I64d",&d);
    vector<long long> primes;
    for(long long i=2;i*i<=d;i++)
    {
        if((d%i)==0) primes.push_back(i);
        while((d%i)==0) d/=i;
    }
    if(d>1) primes.push_back(d);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        long long a,b;
        scanf("%I64d%I64d",&a,&b);
        int one=0;
        int two=0;
        long long res=1;
        for(long long p:primes)
        {
            int now=0;
            while((a%p)==0)
            {
                now++;
                a/=p;
            }
            while((b%p)==0)
            {
                now--;
                b/=p;
            }
            if(now>=0) one+=now;
            else two-=now;
            res=(res*finv[abs(now)])%mod;
        }
        res=(res*f[one])%mod;
        res=(res*f[two])%mod;
        printf("%I64d\n",res);
    }
    return 0;
}