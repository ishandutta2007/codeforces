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
 
const ll   N     =  1e+5+5;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n,u,v,ans[N],vis[N],ct=0,f=1;
vpll adj[N];

void dfs(ll x){
    vis[x] = 1;
    for(auto it : adj[x]){
        if(!vis[it.x]){
            dfs(it.x);
            if(ans[it.y] == -1)ans[it.y] = ct++;
        }
    }
}

int main(){
    fastio;
    cin>>n;
    for(int i = 0; i < n-1; i++){
        cin>>u>>v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }
    for(int i = 0; i < n-1; i++){ ans[i] = -1; }
    for(int i = 1; i <= n; i++){ 
        if(adj[i].size() > 2){
            for(auto it : adj[i]) ans[it.y] = ct++;
            break;
        }
    }
    dfs(1);
    for(int i = 0; i < n-1; i++) cout<<ans[i]<<"\n";
}