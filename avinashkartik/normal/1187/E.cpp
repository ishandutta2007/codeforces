#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<" "<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<" "<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  1e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, m, dp[N], sz[N], vis[N];
vll adj[N];

void dfs(ll x){
    vis[x] = 1;
    sz[x] = 1;
    for(auto it : adj[x]){
        if(vis[it] == 0){ 
            dfs(it);
            sz[x] += sz[it];
        }
    }
}

void reroot(ll x){
    vis[x] = 1;
    for(auto it : adj[x]){
        if(vis[it] == 0){
            dp[it] = dp[x]+n-2*sz[it];
            reroot(it);
        }
    }
}

void solve(){
    cin>>n;
    for(int i = 0; i < n-1; i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    for(int i = 1; i <= n; i++) dp[1] += sz[i];
    mset(vis,0);
    reroot(1);
    ll res = 0;
    for(int i = 1; i <= n; i++) res = max(res,dp[i]);
    deb1(res)
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}