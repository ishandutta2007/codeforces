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
const ll maxn=1e5+10,mod=1e9+7,inf=1e18,lgn=18;
vector<int> G[maxn];
ll a[maxn],visit[maxn],p[maxn],n;

ll gcd(ll t1,ll t2)
{
    while (t2)
    {
        ll r=t1%t2;
        t1=t2;
        t2=r;
    }
    return t1;
}
vector<pii> dv[maxn];

void dfs(int u,int h)
{
    for (int i=0;i<G[u].size();i++)
        if (!p[G[u][i]])
        {
            int v=G[u][i];
            dv[v].pb(mp(a[v],h+1));
            for (int j=0;j<dv[u].size();j++)
            {
                ll tmp=gcd(a[v],dv[u][j].fi);
                if (tmp!=dv[v].back().fi) dv[v].pb(mp(tmp,dv[u][j].se));
            }
            p[v]=u;
            dfs(v,h+1);
        }
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int u,v;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<n;i++)
    {
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    p[1]=1;
    dv[1].pb(mp(a[1],1));
    dfs(1,1);
    ll res=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<dv[i].size()-1;j++) res=(res+dv[i][j].fi*(dv[i][j].se-dv[i][j+1].se))%mod;
        res=(res+dv[i].back().fi*dv[i].back().se)%mod;
    }
    cout<<res;
    return 0;
}