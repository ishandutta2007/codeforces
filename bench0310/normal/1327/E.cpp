#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    const long long mod=998244353;
    vector<long long> p(n+1,1);
    for(int i=1;i<=n;i++) p[i]=(p[i-1]*10)%mod;
    for(int i=1;i<=n;i++)
    {
        if(i==n) printf("10\n");
        else if(i==n-1)
        {
            long long res=(18*p[n-i-1])%mod;
            res=(10*res)%mod;
            printf("%I64d ",res);
        }
        else
        {
            long long res=(81*p[n-i-2])%mod;
            res=(res*(n-2-(i-1)))%mod;
            res=(res+18*p[n-i-1])%mod;
            res=(10*res)%mod;
            printf("%I64d ",res);
        }
    }
    return 0;
}