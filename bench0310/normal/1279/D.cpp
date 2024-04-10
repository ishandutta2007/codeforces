#include <bits/stdc++.h>

using namespace std;

const long long mod=998244353;

long long fastpow(long long b,long long e)
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

long long inv(long long a)
{
    return fastpow(a,mod-2);
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> k(n);
    vector<int> a[n];
    vector<long long> cnt(1000001,0);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&k[i]);
        a[i].resize(k[i]);
        for(int j=0;j<k[i];j++)
        {
            scanf("%d",&a[i][j]);
            cnt[a[i][j]]++;
        }
    }
    long long res=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k[i];j++)
        {
            long long t=inv(n);
            t=(t*inv(n))%mod;
            t=(t*inv(k[i]))%mod;
            t=(t*cnt[a[i][j]])%mod;
            res=(res+t)%mod;
        }
    }
    printf("%I64d\n",res);
    return 0;
}