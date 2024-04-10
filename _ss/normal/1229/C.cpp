#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
#define mp make_pair
const ll maxn=1e5+100,mod=1e9+7,inf=1e18;
vector<int> G[maxn],la[maxn];
ll n,m,q;
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int u,v;
    for (int i=1;i<=m;i++)
    {
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    ll res=0;
    for (int i=1;i<=n;i++)
        for (int j=0;j<G[i].size();j++)
            if (G[i][j]>i) la[i].pb(G[i][j]);
    for (int i=1;i<=n;i++)
    {
        ll t1=G[i].size(),t2=la[i].size();
        res+=(t1-t2)*t2;
    }
    cout<<res<<endl;
    cin>>q;
    for (int i=1;i<=q;i++)
    {
        cin>>u;
        for (int j=0;j<la[u].size();j++)
        {
            v=la[u][j];
            ll t1=G[v].size(),t2=la[v].size();
            res+=-(t1-t2)*t2+(t1-t2-1)*(t2+1);
            la[v].pb(u);
        }
        ll t1=G[u].size(),t2=la[u].size();
        res-=(t1-t2)*t2;
        la[u].clear();
        cout<<res<<endl;
    }
    return 0;
}