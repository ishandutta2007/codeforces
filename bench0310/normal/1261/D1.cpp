#include <bits/stdc++.h>

using namespace std;

const long long mod=998244353;

vector<long long> f(2001,1);
vector<long long> finv(2001,1);

long long add(long long a,long long b)
{
    return ((a%mod)+(b%mod))%mod;
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

long long C(long long n,long long k)
{
    return mul(f[n],mul(finv[k],finv[n-k]));
}

int main()
{
    for(int i=1;i<=2000;i++)
    {
        f[i]=mul(f[i-1],i);
        finv[i]=inv(f[i]);
    }
    long long n,k;
    scanf("%I64d%I64d",&n,&k);
    vector<long long> h(n);
    for(int i=0;i<n;i++) scanf("%I64d",&h[i]);
    int cnt=n;
    for(int i=0;i<n;i++) if(h[i]==h[(i-1+n)%n]) cnt--;
    if(k==1)
    {
        printf("0\n");
        return 0;
    }
    long long res=0;
    for(int a=1;a<=cnt;a++)
    {
        for(int b=0;b<a&&a+b<=cnt;b++)
        {
            int c=cnt-a-b;
            res=add(res,mul(mul(C(cnt,a),C(cnt-a,b)),ex(k-2,c)));
        }
    }
    res=mul(res,ex(k,n-cnt));
    printf("%I64d\n",res);
    return 0;
}