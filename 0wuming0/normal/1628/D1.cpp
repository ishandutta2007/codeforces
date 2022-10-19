#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=1e9+7;
ll dp[2005][2005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,t;
        cin>>n>>m>>t;
        m=n-m;
        for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j]=0;
        dp[n][m]=0;
        for(int i=n;i>=0;i--)dp[i][m]=(n-i)*(ll)t%mod;
        for(int j=m-1;j>=0;j--)for(int i=n-m+j;i>=0;i--)
        {
            dp[i][j]=(dp[i+1][j]+dp[i+1][j+1])*500000004%mod;
        }
        //for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)printf("%lld%c",dp[i][j]," \n"[j==n]);
        cout<<dp[0][0]%mod<<endl;
    }
    return 0;
}