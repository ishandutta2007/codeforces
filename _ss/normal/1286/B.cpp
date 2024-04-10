#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=5e3+10,mod=1e9+7,inf=1e18;
int p[N],c[N],root,n,check=1,ans[N];

vector<int> G[N];
vector<pii> vt[N];

void dfs(int u)
{
    for (int v : G[u])
    {
        dfs(v);
        int tmp;
        if (vt[u].empty()) tmp=0;
        else tmp=vt[u].back().fi;
        for (pii x : vt[v]) vt[u].pb(mp(x.fi+tmp,x.se));
    }
    if (c[u]>(int)vt[u].size())
    {
        check=0;
        return;
    }
    vector<pii> tmp;
    for (int i=0;i<c[u];i++) tmp.pb(vt[u][i]);
    tmp.pb(mp(c[u]+1,u));
    for (int i=c[u];i<(int)vt[u].size();i++) tmp.pb(mp(vt[u][i].fi+1,vt[u][i].se));
    vt[u]=tmp;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>p[i]>>c[i];
        if (!p[i]) root=i;
        G[p[i]].pb(i);
    }
    dfs(root);
    if (!check)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    for (pii x : vt[root]) ans[x.se]=x.fi;
    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
    return 0;
}