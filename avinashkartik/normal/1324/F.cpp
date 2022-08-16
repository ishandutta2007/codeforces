#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
#define  x                     first                 
#define  y                     second                
 
const ll   N     =  2e5+5;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
#define maxBits 22
#define maxMask (1<<maxBits)
 
ll n,a[N],u,v,dp[N],ans[N];
vll adj[N];

ll dfs(ll x, ll par){
    for(auto it : adj[x]){
        if(it != par){
            dp[x] += dfs(it,x);
        }
    }
    dp[x] += a[x];
    return max(0ll,dp[x]);
}

void dfsrr(ll x, ll par){
    ll f = dp[par];
    if(dp[x] > 0) f = dp[par] - dp[x];
    if(f > 0) dp[x] += f;
    //cout<<x<<" "<<par<<" "<<dp[x]<<" "<<dp[par]<<endl;
    ans[x] = dp[x];
    for(auto it : adj[x]){
        if(it != par){
            dfsrr(it,x);
        }
    }
}

int main(){
    fastio;
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= n; i++) if(a[i] == 0) a[i] = -1;
    for(int i = 0; i < n-1; i++){
        cin>>u>>v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    dfs(1,0);
    dfsrr(1,0);
    for(int i = 1; i <= n; i++) cout<<ans[i]<<" ";
}