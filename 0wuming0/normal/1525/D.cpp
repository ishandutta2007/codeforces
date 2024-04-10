#include"bits/stdc++.h"
using namespace std;
int dp[5005][5005];
int a[5005];
int num[5005],nn;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            dp[i][j]=1e8;
        }
    }
    for(int j=0;j<=n;j++)dp[0][j]=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)for(int j=0;j<=n;j++)dp[i][j]=min(dp[i-1][j],dp[i][j]);
        else
        {
            for(int j=2;j<=n;j++)
            {
                dp[i][j]=min(dp[i-1][j-2]+abs(j-1-i)+abs(j-i),dp[i][j]);
            }
        }
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=min(dp[i][j],dp[i][j-1]);
        }
    }
    cout<<dp[n][n]<<endl;
    return 0;
}
/*
2
1 0
*/