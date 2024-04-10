#include"bits/stdc++.h"
using namespace std;
char s[405][405];
int sum[405][405];
int dp[405][405];
int num(int x1,int y1,int x2,int y2)
{
    x1--;
    y1--;
    return sum[x2][y2]-sum[x1][y2]-sum[x2][y1]+sum[x1][y1];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<=m;i++)for(int j=0;j<=m;j++)dp[i][j]=100000;
        for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
        {
            sum[i][j]=s[i][j]-'0';
        }
        int ans=100000;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)sum[i][j]+=sum[i-1][j];
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)sum[i][j]+=sum[i][j-1];
        for(int i=4;i<n;i++)for(int l=1;l<=m;l++)for(int r=l+3;r<=m;r++)
        {
            dp[l][r]+=num(i,l+1,i,r-1);
            if(s[i][l]=='0')dp[l][r]++;
            if(s[i][r]=='0')dp[l][r]++;
            int now=0;//i-2  i-3
            now+=num(i-2,l+1,i,r-1);
            now+=r-l-1+6;
            now-=num(i-2,l,i,l);
            now-=num(i-2,r,i,r);
            now-=num(i-3,l+1,i-3,r-1);
            dp[l][r]=min(dp[l][r],now);
            ans=min(dp[l][r]+r-l-1-num(i+1,l+1,i+1,r-1),ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
1
6 6
011110
100001
100001
100001
100001
111111
*/