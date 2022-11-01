#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,h,l,r;
    scanf("%d%d%d%d",&n,&h,&l,&r);
    vector<vector<int>> dp(n+1,vector<int>(h,-1));
    dp[0][0]=0;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        for(int j=0;j<h;j++)
        {
            if(dp[i][j]==-1) continue;
            dp[i+1][(j+a)%h]=max(dp[i+1][(j+a)%h],dp[i][j]+(l<=((j+a)%h)&&((j+a)%h)<=r));
            dp[i+1][(j+a-1)%h]=max(dp[i+1][(j+a-1)%h],dp[i][j]+(l<=((j+a-1)%h)&&((j+a-1)%h)<=r));
        }
    }
    int res=0;
    for(int i=0;i<h;i++) res=max(res,dp[n][i]);
    printf("%d\n",res);
    return 0;
}