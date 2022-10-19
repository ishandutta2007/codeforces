#include <bits/stdc++.h>
/// 500 485
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=3e5+100;
vector <int> g[N];
ll vis[N];
ll dfs(ll v){
    vis[v]=1;
    for (auto u : g[v]){
        if (vis[u]==0) dfs(u);
    }
}
set <int> s;
int32_t Main(){
    ll n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        g[i].clear();
        vis[i]=0;
    }
    for (int i=1;i<=m;i++){
        ll u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1);
    for (int i=1;i<=n;i++) if (!vis[i]) kill("NO");
    for (int i=1;i<=n;i++) vis[i]=0;
    s.insert(1);
    vector <int> ans;
    while(s.size()){
        ll v=*s.begin();
        s.erase(s.begin());
        ans.pb(v);
        vector <int> ras;
        vis[v]=1;
        for (auto u : g[v]){
            if (vis[u]) continue;
            vis[u]=1;
            s.erase(u);
            ras.pb(u);
        }
        for (auto u : ras){
            for (auto z : g[u]){
                if (vis[z]==0) s.insert(z);
            }
        }
    }
    cout << "YES" << endl;
    cout << ans.size() << endl;
    for (auto u : ans) cout << u << " ";
    cout << endl;
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();
}