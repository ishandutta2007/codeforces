#include"bits/stdc++.h"
using namespace std;
bool m[705][705];
bool dp[705][705];
int a[705];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
    {
        if(__gcd(a[i],a[j])!=1)m[i][j]=1;
    }
    for(int i=1;i<=n;i++)dp[i][i]=1;
    for(int dis=1;dis<=n;dis++)for(int i=1;i+dis<=n;i++)
    {
        int j=i+dis;
        for(int k=i+1;k<=j;k++)if(m[i][k]&&dp[k][i+1]&&dp[k][j])dp[i][j]=1;
        for(int k=i;k<=j-1;k++)if(m[j][k]&&dp[k][i]&&dp[k][j-1])dp[j][i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(dp[i][1]&&dp[i][n])
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}