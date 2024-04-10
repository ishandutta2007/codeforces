#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100,M=20;
vector <int> g[N];
ll val[N];
ll hi[N];
ll vis[N];
ll par[N][M];
ll getpar(ll v,ll h){
    if (h<=0) return v;
    for (int i=M-1;i>-1;i--){
        if ((h & (1<<i))) v=par[v][i];
    }
    return v;
}
ll lca(ll u,ll v){
    if (hi[u]<hi[v]) swap(u,v);
    u=getpar(u,hi[u]-hi[v]);
    if (u==v) return v;
    for (int i=M-1;i>-1;i--){
        if (par[v][i]!=par[u][i]){
            v=par[v][i];
            u=par[u][i];
        }
    }
    return par[v][0];
}
ll dfsj(ll v,ll p){
    vis[v]=1;
    for (auto u : g[v]){
        if (vis[u]==0){
            dfsj(u,v);
            val[v]+=val[u];
        }
    }
}
ll dfs(ll v,ll p){
    hi[v]=hi[p]+1;
    vis[v]=1;
    par[v][0]=p;
    for (auto u : g[v]){
        if (vis[u]==0){
            dfs(u,v);
        }
        else if (u!=p){
            if (hi[u]<hi[v]){
                val[v]++;
                val[u]--;
              //  cout << v << " " << u << endl;
            }
        }
    }
}
int32_t main(){
    sync;
    ll n,m;
    cin >> n >> m;
    for (int i=1;i<=m;i++){
        ll u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i=1;i<=n;i++){
        if (vis[i]==0) dfs(i,i);
    }
    memset(vis,0,sizeof vis);
    for (int i=1;i<=n;i++){
        if (vis[i]==0) dfsj(i,i);
    }
    ll ras=0;
    for (int i=1;i<=n;i++){
        if (val[i]>=2) ras=i;
    }
    if (ras==0) kill("NO");
    cout << "YES" << endl;
    for (int i=1;i<M;i++){
        for (int j=1;j<=n;j++){
            par[j][i]=par[par[j][i-1]][i-1];
        }
    }
    vector <pii> bk;
    for (int v=1;v<=n;v++){
        for (auto u : g[v]){
            if (hi[u]<hi[v]) continue;
            if (hi[u]-hi[v]==1) continue;
            if (lca(ras,v)!=v || lca(u,ras)!=ras) continue;
            bk.pb({u,v});
        }
    }
    ll u=bk[0].F,v=bk[0].S,x=bk[1].F,y=bk[1].S;
    ll f=lca(u,x);
    ll z=v;
    if (hi[y]>hi[z]){
        z=y;
        swap(y,v);
        swap(u,x);
    }
    vector <int> ans[3];
    ll s=f;
    while(s!=z){
        ans[0].pb(s);
        s=par[s][0];
    }
    ans[0].pb(z);
    ans[1].pb(z);
    s=u;
    while(s!=f){
        ans[1].pb(s);
        s=par[s][0];
    }
    ans[1].pb(f);
    reverse(ans[1].begin(),ans[1].end());
    s=z;
    while(s!=y){
        ans[2].pb(s);
        s=par[s][0];
    }
    ans[2].pb(y);
    s=x;
    while(s!=f){
        ans[2].pb(s);
        s=par[s][0];
    }
    ans[2].pb(f);
    reverse(ans[2].begin(),ans[2].end());
    cout << ans[0].size() << " ";
    for (auto u : ans[0]){
        cout << u << " ";
    }
    cout << endl;
    cout << ans[1].size() << " ";
    for (auto u : ans[1]){
        cout << u << " ";
    }
    cout << endl;
    cout << ans[2].size() << " ";
    for (auto u : ans[2]){
        cout << u << " ";
    }
}