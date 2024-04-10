#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=3e5+100,M=20;
vector <int> g[N];
ll pr[N];
ll par[N][M];
ll hi[N];
ll val[N];
ll ans[N];
void dfsval(ll v,ll p){
    for (auto u : g[v]){
        if (u==p) continue;
        dfsval(u,v);
        val[v]+=val[u];
    }
    if (val[v]%2!=0) {
        ans[v]++;
        ans[p]++;
    }
}
void dfs(ll v,ll p,ll h){
    par[v][0]=p;
    hi[v]=h;
    for (auto u : g[v]){
        if (u==p) continue;
        dfs(u,v,h+1);
    }
}
ll get(ll v,ll h){
    for (int i=0;i<M;i++){
        if ((h & (1<<i))) v=par[v][i];
    }
    return v;
}
ll lca(ll v,ll u){
    if (hi[v]<hi[u]){
        swap(v,u);
    }
    v=get(v,hi[v]-hi[u]);
    if (v==u) return v;
    for (int i=M-1;i>-1;i--){
        if (par[v][i]!=par[u][i]){
            v=par[v][i];
            u=par[u][i];
        }
    }
    return par[v][0];
}
ll getpar(ll v){
    if (pr[v]==v) return v;
    return pr[v]=getpar(pr[v]);
}
int Main(){
    ll n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++) pr[i]=i;
    for (int i=1;i<=m;i++){
        ll u,v;
        cin >> u >> v;
        ll u1=getpar(u);
        ll v1=getpar(v);
        if (u1!=v1){
            pr[u1]=v1;
            g[u].pb(v);
            g[v].pb(u);
        }
    }
    dfs(1,1,0);
    for (int i=1;i<M;i++){
        for (int j=1;j<=n;j++){
            par[j][i]=par[par[j][i-1]][i-1];
        }
    }
    ll q;
    cin >> q;
    vector <pii> a;
    while(q--){
        ll u,v;
        cin >> u >> v;
        a.pb({u,v});
        ll f=lca(u,v);
        val[u]++;
        val[v]++;
        val[f]-=2;
    }
    dfsval(1,1);
    ll e=0;
    for (int i=1;i<=n;i++){
        if (ans[i]%2==1) e++;
    }
    if (e>0){
        cout << "NO" << endl;
        kill(e/2);
    }
    cout << "YES" << endl;
    for (auto U : a){
        ll u=U.F;
        ll v=U.S;
        ll f=lca(u,v);
        cout << hi[u]-hi[f]+hi[v]-hi[f]+1 << endl;
        while(u!=f){
            cout << u << " " ;
            u=par[u][0];
        }
        cout << f << " ";
        vector <int> b;
        while(v!=f){
            b.pb(v);
            v=par[v][0];
        }
        reverse(b.begin(),b.end());
        for (auto z : b){
            cout << z << " ";
        }
        cout << endl;
    }
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
   // cin >> t;
    while(t--) Main();
}
/*
1
1
1
2

2

0

0

4

4

1
*/