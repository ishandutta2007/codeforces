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

ll test = 1, n, m, vis[N], rec[N], ind[N], no = 0;
vll adj[N];
vpll rem;
stack <ll> Stack;

void TSUtil(int v){ 
    vis[v] = 1;
    for(auto it : adj[v]) 
        if (!vis[it]) 
            TSUtil(it); 
    Stack.push(v); 
} 

void TS(){ 
    for(int i = 1; i <= n; i++) vis[i] = 0;
    for(int i = 1; i <= n; i++)
        if(!vis[i])
            TSUtil(i);
    while(Stack.empty() == 0){ 
        ind[Stack.top()] = no++; 
        Stack.pop(); 
    }
}

void solve(){
    no = 0;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        rem.pb({u,v});
    }
    TS();
    int res = 1;
    for(auto it : rem) if(ind[it.f] > ind[it.s]) res = 2;
    deb1(res)
    for(auto it : rem){
        if(ind[it.f] > ind[it.s]) cout<<2<<" ";
        else cout<<1<<" ";
    }
    cout<<endl;
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
}