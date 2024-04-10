#include<bits/stdc++.h>
using namespace std;
long long s[5009][5009];
long long  n,m,k,mod=998244353,ans;
long long fastpow(long long x,long long y)
{
    long long res=1;
    while(y)
    {
        if(y%2==1)res=(res*x)%mod;
        x=(x*x)%mod;
        y=y/2;
    }
    return res;
}
int main()
{
    cin>>n>>m>>k;
    s[0][0]=1;
    for(int i=1;i<=k;i++)
        for(int j=1;j<=i;j++)
            s[i][j]=(s[i-1][j]*j+s[i-1][j-1]*(n+1-j))%mod;
    for(int i=1;i<=k;i++)ans+=s[k][i]*fastpow(fastpow(m,mod-2),i)%mod,ans%=mod;
    cout<<ans<<endl;
    return 0;
}