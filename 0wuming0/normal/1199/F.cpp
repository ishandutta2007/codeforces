#include"bits/stdc++.h"
using namespace std;
char s[52][52];
int dp[52][52][52][52];
int sum1[52][52][52],sum2[52][52][52];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)if(s[i][j]=='.')sum1[i][j][j]=1;
        for(int j=1;j<=n;j++)if(s[j][i]=='.')sum2[i][j][j]=1;
        for(int d=1;d<n;d++)for(int j=1;j+d<=n;j++)
        {
            if(sum1[i][j][j+d-1]==1&&s[i][j+d]=='.')sum1[i][j][j+d]=1;
            if(sum2[i][j][j+d-1]==1&&s[j+d][i]=='.')sum2[i][j][j+d]=1;
        }
    }
    for(int di=0;di<n;di++)for(int dj=0;dj<n;dj++)for(int i=1;i+di<=n;i++)for(int j=1;j+dj<=n;j++)
    {
        int i2=i+di,j2=j+dj;
        int ans=max(di,dj);
        ans++;
        for(int k=i;k<=i2;k++)if(sum1[k][j][j2]==1)
        {
            ans=min(ans,dp[i][k-1][j][j2]+dp[k+1][i2][j][j2]);
        }
        for(int k=j;k<=j2;k++)if(sum2[k][i][i2]==1)
        {
            ans=min(ans,dp[i][i2][j][k-1]+dp[i][i2][k+1][j2]);
        }
        dp[i][i2][j][j2]=ans;
    }
    cout<<dp[1][n][1][n]<<endl;
    return 0;
}