#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=1e5+10,mod=1e9+7,inf=1e18;
ll dp1[12][1010],n,m,dp2[12][1010];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) dp1[1][i]=dp2[1][i]=1;
    for (int i=2;i<=m;i++)
        for (int j=1;j<=n;j++) dp1[i][j]=(dp1[i][j-1]+dp1[i-1][j])%mod;
    for (int i=2;i<=m;i++)
        for (int j=n;j;j--) dp2[i][j]=(dp2[i][j+1]+dp2[i-1][j])%mod;
    ll res=0;
    for (int i=1;i<=n;i++)
    {
        dp1[m][i]=(dp1[m][i-1]+dp1[m][i])%mod;
        res=(res+dp1[m][i]*dp2[m][i])%mod;
    }
    cout<<res;
    return 0;
}