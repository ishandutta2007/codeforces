#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  5e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, a[N], dp[N], sz[N], ans = 0;
vll adj[N];

void reroot(int x, int par){
    if(par){
        dp[par] -= dp[x]+sz[x];
        sz[par] -= sz[x];
        dp[x] += dp[par]+sz[par];
        sz[x] += sz[par];
        ans = max(ans,dp[x]);
    }
    for(auto it : adj[x]){
        if(it == par) continue;
        reroot(it,x);
    }
    if(par){
        dp[x] -= dp[par]+sz[par];
        sz[x] -= sz[par];
        dp[par] += dp[x]+sz[x];
        sz[par] += sz[x];
    }
}

void dfs(int x, int par){
    sz[x] = a[x];
    for(auto it : adj[x]){
        if(it == par) continue;
        dfs(it,x);
        dp[x] += dp[it]+sz[it];
        sz[x] += sz[it];
    }
}

void solve(){
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i < n; i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    ans = dp[1];
    reroot(1,0);
    deb1(ans)
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