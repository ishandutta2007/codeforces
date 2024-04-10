#include"bits/stdc++.h"
using namespace std;
int dp[205][512];
int a[205],b[205];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=0;k<512;k++)
            {
                if(dp[i-1][k])
                {
                    dp[i][k|(a[i]&b[j])]=1;
                }
            }
        }
    }
    for(int k=0;;k++)if(dp[n][k])
    {
        cout<<k<<endl;
        return 0;
    }
    return 0;
}