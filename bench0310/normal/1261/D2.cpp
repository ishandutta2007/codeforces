#include <bits/stdc++.h>

using namespace std;

const long long mod=998244353;

const int N=200001;
vector<long long> f(N,1);
vector<long long> finv(N,1);
vector<long long> kpow(N,1);

long long add(long long a,long long b)
{
    return ((a%mod)+(b%mod))%mod;
}

long long sub(long long a,long long b)
{
    return ((a%mod)-(b%mod)+mod)%mod;
}

long long mul(long long a,long long b)
{
    return ((a%mod)*(b%mod))%mod;
}

long long ex(long long b,long long e)
{
    long long t=1;
    while(e)
    {
        if(e&1) t=mul(t,b);
        e/=2;
        b=mul(b,b);
    }
    return t;
}

long long inv(long long a)
{
    return ex(a,mod-2);
}

long long choose(long long n,long long k)
{
    return mul(f[n],mul(finv[k],finv[n-k]));
}

int main()
{
    long long n,k;
    scanf("%I64d%I64d",&n,&k);
    for(int i=1;i<N;i++)
    {
        f[i]=mul(f[i-1],i);
        kpow[i]=mul(kpow[i-1],k-2);
    }
    finv[N-1]=inv(f[N-1]);
    for(int i=N-2;i>=0;i--) finv[i]=mul(finv[i+1],i+1);
    vector<long long> h(n);
    for(int i=0;i<n;i++) scanf("%I64d",&h[i]);
    if(k==1)
    {
        printf("0\n");
        return 0;
    }
    int m=n;
    for(int i=0;i<n;i++) if(h[i]==h[(i-1+n)%n]) m--;
    long long res=0;
    for(int i=0;2*i<=m;i++)
    {
        res+=mul(mul(choose(m,i),choose(m-i,i)),kpow[m-2*i]);
    }
    res=mul(res,ex(k,n-m));
    res=sub(ex(k,n),res);
    res=mul(res,inv(2));
    printf("%I64d\n",res);
    return 0;
}