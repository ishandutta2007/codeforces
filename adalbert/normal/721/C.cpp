#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define sec second
#define mp make_pair
#define pb push_back


vector <ll> vec[5001],cina[5001],ts,vec1;
ll in[5001],dp[5001][5001],pred[5001][5001];
///--------------------------------------------------------------------------------------------------------------///
void dfs(ll u)
{
    //cout<<u<<'\n';
    in[u]=1;
    for (int i=0;i<vec[u].size();i++)
        if (in[vec[u][i]]==0) dfs(vec[u][i]);
    ts.pb(u);
}
int main()
{
    ll n,m,t;
    cin>>n>>m>>t;
    for (int i=1;i<=m;i++)
    {
        ll st,fin,cost;
        cin>>st>>fin>>cost;
        vec[st].pb(fin);
        cina[st].pb(cost);
    }
    dfs(1);
    reverse(ts.begin(),ts.end());
    for (int i=0;i<=n;i++)
        for (int j=0;j<=n;j++)
        dp[i][j]=1e9+1;
    dp[1][1]=0;
    for (int i=0;i<ts.size();i++)
    for (int v=0;v<=n;v++)
    {
        for (int j=0;j<vec[ts[i]].size();j++)
        {
            if (dp[ts[i]][v]+cina[ts[i]][j]<dp[vec[ts[i]][j]][v+1])
            {
                dp[vec[ts[i]][j]][v+1]=min(dp[vec[ts[i]][j]][v+1],dp[ts[i]][v]+cina[ts[i]][j]);
                pred[vec[ts[i]][j]][v+1]=ts[i];
            }
        }
    }
    ll ans;
    for (int v=0;v<=n;v++)
    {
        if (dp[n][v]<=t) ans=v;
    }
    ll tep=n;
    for (int i=1;i<=ans;i++)
    {
        vec1.pb(tep);
        tep=pred[tep][ans-i+1];
    }
    cout<<ans<<'\n';
    reverse(vec1.begin(),vec1.end());
    for (int i=0;i<vec1.size();i++)
        cout<<vec1[i]<<' ';

}