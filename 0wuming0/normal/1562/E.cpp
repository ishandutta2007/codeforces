#include"bits/stdc++.h"
using namespace std;
char s[5005];
int same[5005][5005];
int dp[5005][5005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,ans=0;
        scanf("%d",&n);
        scanf("%s",s);
        for(int dis=1;dis<n;dis++)for(int i=n-dis;i>=0;i--)
        {
            int j=i+dis;
            if(s[i]==s[j])same[i][j]=same[i+1][j+1]+1;
            else same[i][j]=0;
        }
        dp[n-1][n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j<n;j++)dp[i][j]=n-j;
            for(int j=i+1;j<n;j++)if(j+same[i][j]!=n)
            {
                if(s[i+same[i][j]]<s[j+same[i][j]])dp[i][n-1]=max(dp[j][j+same[i][j]]+1,dp[i][n-1]);
                else if(same[i][j])dp[i][i+same[i][j]-1]=max(dp[j][j+same[i][j]]+1,dp[i][i+same[i][j]-1]);
            }
            for(int j=n-2;j>=i;j--)dp[i][j]=max(dp[i][j+1]+1,dp[i][j]);
        }
        for(int i=0;i<n;i++)for(int j=i;j<n;j++)ans=max(dp[i][j],ans);
        printf("%d\n",ans);
    }
    return 0;
}