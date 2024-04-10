#include"bits/stdc++.h"
using namespace std;
int dp[5005][5005];
char s1[5005],s2[5005];
int bestj[5005];
int n,m;
int main()
{
    cin>>n>>m;
    scanf("%s%s",s1,s2);
    for(int i=0;i<5005;i++)for(int j=0;j<5005;j++)dp[i][j]=-1000000000;
    for(int i=0;i<5005;i++)bestj[i]=-1000000000;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(s1[i]==s2[j])dp[i][j]=2;
    for(int i=0;i<1;i++)
    {
        for(int j=1;j<m;j++)dp[i][j]=max(dp[i][j],dp[i][j-1]-1);
        for(int j=0;j<m;j++)bestj[j]=dp[i][j];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)if(s1[i]==s2[j])dp[i][j]=max(dp[i][j],dp[i-1][j-1]+2);
        for(int j=1;j<m;j++)dp[i][j]=max(dp[i][j],dp[i][j-1]-1);
        for(int j=0;j<m;j++)dp[i][j]=max(dp[i][j],dp[i-1][j]-1);
    }//cout<<dp[1][0]<<endl;
    int best=0;
    for(int i=0;i<5005;i++)for(int j=0;j<5005;j++)best=max(best,dp[i][j]);
    cout<<best<<endl;
    return 0;
}
/*
3 2
abc
ac
*/