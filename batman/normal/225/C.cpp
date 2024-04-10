#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define N (1111)
ll n,m,x,y,dp[2][N],need[2][N];

int main()
{
    cin>>n>>m>>x>>y;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            char c;
            cin>>c;
            if(c=='#')need[0][j]++;
            else need[1][j]++;
        }
    //dp[0][0]=need[0][0],dp[1][0]=need[1][0];
    //cout<<dp[0][0]<<" "<<dp[1][0]<<"\n";
    for(int i=0;i<m;i++)
    {
        dp[0][i]=dp[1][i]=1e9;
        ll sum[2]={};
        for(int j=i;j>i-y && j>=0;j--)
        {
            sum[0]+=need[0][j],sum[1]+=need[1][j];
            if(j<=i-x+1)
                dp[0][i]=min(dp[0][i],sum[0]+((j)?dp[1][j-1]:0)),dp[1][i]=min(dp[1][i],sum[1]+((j)?dp[0][j-1]:0));
        }   
        //cout<<dp[0][i]<<" "<<dp[1][i]<<"\n";
    }   
    cout<<min(dp[0][m-1],dp[1][m-1]);
    return 0;
}