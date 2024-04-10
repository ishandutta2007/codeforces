#include <bits/stdc++.h>
using namespace std;
#define ll long long
///----------------------------------------------------------///


ll type,y,ans,n,m,dp[4000][4000];
pair <ll,ll > h[10000];

///----------------------------------------------------------///
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>h[i].first>>h[i].second;
    }
    dp[0][0]=1;
    for (int i=1;i<=n;i++)
    {
        for (int j=300;j>=0;j--)
            for (int l=300;l>=0;l--)
            {
                if (dp[j][l]!=0)
                {
                    dp[j+h[i].first][l]=max(dp[j+h[i].first][l],dp[j][l]+1);
                    dp[j][l+h[i].second]=max(dp[j][l+h[i].second],dp[j][l]+1);
                }

            }
    }
    for (int i=1;i<=400;i++)
        for (int j=0;j<=i;j++)
        if (dp[i][j]==n+1)
        {
            cout<<i;
            return(0);
        }

}