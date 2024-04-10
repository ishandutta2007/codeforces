#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=1e3+10,mod=1e9+7,inf=1e9;
int p[N],n,dp[N][N][2],ps[N];

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i];
    for (int i=1;i<=n;i++)
        if (p[i]) ps[i]=ps[i-1];
        else ps[i]=ps[i-1]+1;
    int cap0=n/2,cap1=(n+1)/2;
    for (int i=1;i<=n;i++)
        if (p[i])
        {
            if (p[i]&1) cap1--;
            else cap0--;
        }
    for (int i=1;i<=n;i++)
        for (int j=0;j<=cap1;j++)
            for (int t=0;t<=1;t++) dp[i][j][t]=inf;
    if (p[1]) dp[1][0][p[1]&1]=0;
    else dp[1][0][0]=dp[1][1][1]=0;
    for (int i=1;i<n;i++)
        for (int j=0;j<=cap1;j++)
        if (p[i+1])
        {
            if (p[i+1]&1) dp[i+1][j][1]=min({dp[i+1][j][1],dp[i][j][0]+1,dp[i][j][1]});
            else dp[i+1][j][0]=min({dp[i+1][j][0],dp[i][j][0],dp[i][j][1]+1});
        }
        else
        {
            if (ps[i]-j<cap0) dp[i+1][j][0]=min({dp[i+1][j][0],dp[i][j][0],dp[i][j][1]+1});
            if (j<cap1) dp[i+1][j+1][1]=min({dp[i+1][j+1][1],dp[i][j][0]+1,dp[i][j][1]});
        }
    cout<<min(dp[n][cap1][1],dp[n][cap1][0]);
    return 0;
}