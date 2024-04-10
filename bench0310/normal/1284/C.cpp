#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,m;
    scanf("%I64d%I64d",&n,&m);
    vector<long long> f(n+1,1);
    for(long long i=1;i<=n;i++) f[i]=(f[i-1]*i)%m;
    long long res=0;
    for(long long len=1;len<=n;len++)
    {
        long long cnt=1;
        cnt=(cnt*(n-len+1))%m;
        cnt=(cnt*(n-len+1))%m;
        cnt=(cnt*f[len])%m;
        cnt=(cnt*f[n-len])%m;
        res=(res+cnt)%m;
    }
    printf("%I64d\n",res);
    return 0;
}