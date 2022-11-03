#include <bits/stdc++.h>
using namespace std;
int dp[5001][5001],ans,a,b,n,k,pref[5001][5001];
typedef long long ll;
const ll md=1e9+7;
int main()
{
    //return cout<<(sizeof(dp)>>10), 0;
    cin>>n>>a>>b>>k;
    if (a>b)
    {
        a=n-a+1;
        b=n-b+1;
    }

    dp[0][a]=1;
    for (int j=1;j<=n;j++)
        pref[0][j]=pref[0][j-1]+dp[0][j];




    for (int i=1;i<=k;i++)
        for (int j=1;j<=b-1;j++)
    {
        dp[i][j]=(pref[i-1][j+(b-j)/2-((b-j)%2==0)]-dp[i-1][j]+md)%md;
        pref[i][j]=(pref[i][j-1]+dp[i][j]+md)%md;
    }
    cout<<pref[k][b-1];

}