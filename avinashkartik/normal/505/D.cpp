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
#define  deb1(a)        cout<<a<<" "<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<" "<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<pll,ll>  um;
typedef  vector<pll>           vpll;
 
const int   N    =  3e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test=1,n,m,vis[N],rec[N],cyc[N],p[N],sz[N];
vll adj[N];

void make(ll n){
    for(int i = 1; i <= n; i++){
        p[i] = i;
        sz[i] = 1;
    }
}

int find(ll x){
    return (p[x] == x)? x: p[x] = find(p[x]);
}

void merge(ll x, ll y){
    ll a = find(x);
    ll b = find(y);
    if(a != b){
        if(sz[a] >= sz[b]) swap(a,b);
        p[a] = b;
        sz[b] += sz[a];
    }
}

bool CycleUtil(int v){ 
    if(vis[v] == 0){
        vis[v] = 1, rec[v] = 1; 
        for(auto it : adj[v]) { 
            if(!vis[it] && CycleUtil(it)) 
                return 1; 
            else if(rec[it]) 
                return 1; 
        } 
    } 
    rec[v] = 0;
    return 0; 
}

void Cycle(){
    for(int i = 1; i <= n; i++) 
        if(CycleUtil(i)) 
            cyc[find(i)] = 1;
}

void solve(){
    cin>>n>>m;
    make(n);
    for(int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        merge(u,v);
    }
    Cycle();
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        if(find(i) == i){
            if(cyc[i] == 1) ans += sz[i];
            else ans += sz[i]-1;
        }
    }
    deb1(ans)
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
}