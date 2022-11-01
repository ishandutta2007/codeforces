#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> v(n+2,0);
    for(int i=1;i<=n;i++) scanf("%d",&v[i]);
    int dp[n+2][n+2];
    int val[n+2][n+2];
    for(int o=0;o<=n+1;o++) for(int i=0;i<=n+1;i++) dp[o][i]=val[o][i]=0;
    for(int i=1;i<=n;i++) val[i][i]=v[i];
    for(int o=1;o<n;o++)
    {
        for(int i=1;i+o<=n;i++)
        {
            int &now=dp[i][i+o];
            for(int j=i;j<i+o;j++)
            {
                now=max(now,dp[i][j]+dp[j+1][i+o]);
                if(dp[i][j]==j-i&&dp[j+1][i+o]==i+o-j-1&&val[i][j]==val[j+1][i+o])
                {
                    now=max(now,1+dp[i][j]+dp[j+1][i+o]);
                    val[i][i+o]=val[i][j]+1;
                }
            }
        }
    }
    printf("%d\n",n-dp[1][n]);
    return 0;
}