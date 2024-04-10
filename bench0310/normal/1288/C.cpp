#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int mod=1000000007;
    int n,m;
    scanf("%d%d",&n,&m);
    vector<vector<int>> dp(2*m+1,vector<int>(n+1,0));
    dp[0][1]=1;
    for(int o=1;o<=2*m;o++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                dp[o][i]=(dp[o][i]+dp[o-1][j])%mod;
            }
        }
    }
    int res=0;
    for(int i=1;i<=n;i++) res=(res+dp[2*m][i])%mod;
    printf("%d\n",res);
    return 0;
}