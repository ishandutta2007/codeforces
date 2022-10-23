#include <bits/stdc++.h>

using namespace std;
const int N=4e3+10,mod=1e9+7;
char a[N];
int n,k;
long long dp[N][N],dp2[N][N];
int main()
{
    //freopen("ss.inp","r",stdin);
    cin>>n>>k;
    cin>>(a+1);
    dp[0][0]=dp2[0][0]=1;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=k;j++)
        {
            dp[i][j]=dp[i-1][j]*(a[i]-'a'+1)%mod;
            for (int t=0;t<j/(n-i+1) && i-t>0;t++) dp[i][j]=(dp[i][j]+('z'-a[i])*dp2[i-t-1][j-(t+1)*(n-i+1)])%mod;
            dp2[i][j]=(dp[i][j]-dp[i-1][j]+mod)%mod;
        }
    cout<<dp[n][k];
    return 0;
}