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
const int N=2e5+100;
vector <int> g[N];
ll sz[N];
ll cen=0;
ll n;
ll dfsfind(ll v,ll p){
    sz[v]=1;
    ll z=0;
    for (auto u : g[v]){
        if (u==p) continue;
        dfsfind(u,v);
        sz[v]+=sz[u];
        if (sz[u]>n/2) z=1;
    }
    if (z==0 && n-sz[v]<=n/2) cen=v;
  //  cout << v << " " << sz[v] << endl;
}
ll hi[N];
ll dfs(ll v,ll p){
    sz[v]=1;
    hi[v]=1+hi[p];
    for (auto u : g[v]){
        if (u==p) continue;
        dfs(u,v);
        sz[v]+=sz[u];
    }
}
ll val=1;
ll zar;
ll ans[N];
ll dfsans(ll v,ll p){
    ans[v]=val;
    val+=zar;
    for (auto u : g[v]){
        if (u==p) continue;
        dfsans(u,v);
    }
}
int32_t main(){
   // ll n;
    cin >> n;
    if (n==1) return 0;
    vector <pii> yal;
    for (int i=1;i<n;i++){
        ll u,v;
        cin >> u >> v;
        yal.pb({u,v});
        g[u].pb(v);
        g[v].pb(u);
    }
    dfsfind(1,1);
   // cout << cen << endl;
    dfs(cen,cen);
    vector <pii> bh;
    for (auto u : g[cen]){
        bh.pb({sz[u],u});
    }
    sort(bh.begin(),bh.end());
    ll cnt=0;
    while(cnt<=n/3){
        cnt+=bh.back().F;
        zar=1;
        dfsans(bh.back().S,cen);
        bh.pop_back();
    }
    for (auto u : bh){
        zar=cnt+1;
       // cout << cnt+1 << " " << val << " " << u.F << " " << u.S  << endl;
        dfsans(u.S,cen);
    }
    for (int i=0;i<yal.size();i++){
        ll u=yal[i].F,v=yal[i].S;
        if (hi[u]<hi[v]) swap(u,v);
        cout << u << " " << v << " " << ans[u]-ans[v] << endl;
    }
}