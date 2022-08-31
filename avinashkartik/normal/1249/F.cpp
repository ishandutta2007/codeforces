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
 
const ll   N     =  205;
const ll   MAXN  =  1e7+1;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, k, a[N], dp[N][N] = {}, depth[N] = {}, mx = 0;
vll adj[N];

void dfs(int x, int p){
    depth[x] = depth[p]+1;
    mx = max(mx,depth[x]);
    dp[x][depth[x]] = a[x];
    for(auto it : adj[x]){
        if(it != p){
            dfs(it,x);
            ll d[N] = {};
            for(int i = depth[x]; i <= mx; i++){
                for(int j = depth[x]; j <= mx; j++){
                    if(abs(depth[x]-i) + abs(depth[x]-j) <= k) continue;
                    d[min(i,j)] = max(d[min(i,j)],dp[x][i]+dp[it][j]);
                }
            }
            for(int i = depth[x]; i <= mx; i++) dp[x][i] = max(dp[x][i],max(d[i],dp[it][i]));
        }
    }
}

void solve(){
    cin>>n>>k;
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i < n; i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    ll ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= mx; j++)
            ans = max(ans,dp[i][j]);
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