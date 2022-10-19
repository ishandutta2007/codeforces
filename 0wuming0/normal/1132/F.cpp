#include"bits/stdc++.h"
using namespace std;
int dp[505][505];
char s[505];
int main()
{
    int n;
    cin>>n;
    scanf("%s",s+1);
    for(int d=0;d<n;d++)for(int i=1;i+d<=n;i++)
    {
        int j=i+d;
        if(d==0)
        {
            dp[i][j]=1;
            continue;
        }
        dp[i][j]=10000;
        for(int k=i;k<j;k++)
        {
            dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
            if(s[k]==s[j])
            {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j-1]);
            }
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}