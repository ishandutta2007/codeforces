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
#define  deb1(a)        cout<<a<<" ";
#define  deb2(a,b)      cout<<a<<" "<<b<<" "<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  1e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test=1,n,m,lvl[N],par[N][20],tin[N],tout[N],ct = 0,sz[N];
vll adj[N];
set <pll> LVL[N];

void dfs(ll x){
    tin[x] = ct++;
    if(x != 0) LVL[lvl[x]].insert({tin[x],++sz[lvl[x]]});
    for(auto it : adj[x]){
        lvl[it] = lvl[x]+1;
        par[it][0] = x;
        for(int i = 1; i < 20; i++){
            par[it][i] = par[par[it][i-1]][i-1];
        }
        dfs(it);
    }
    tout[x] = ct++;
}

int findpar(ll x, ll p){
    if(p == 0) return x;
    for(int i = 19; i >= 0; i--){
        int y = (1<<i);
        if(p&y){
            return findpar(par[x][i],p-y);
        }
    }
}

void solve(){
    cin>>n;
    for(int i = 1; i <= n; i++){
        int u;
        cin>>u;
        adj[u].pb(i);
    }
    mset(par,0);
    lvl[0] = -1;
    dfs(0);
    cin>>m;
    while(m--){
        int v,p;
        cin>>v>>p;
        if(lvl[v] < p) deb1(0)
        else{
            int x = findpar(v,p);
            if(x == 0) deb1(0)
            else{
                int dpth = lvl[v];
                auto p1 = LVL[dpth].upper_bound({tin[x],INF});
                auto p2 = LVL[dpth].upper_bound({tout[x],INF});
                p2--;
                deb1((*p2).s-(*p1).s)
            }
        }
    }
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