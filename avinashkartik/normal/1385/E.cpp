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
vector <pair<ll,pll>> rem;
stack <ll> Stack;

void TSUtil(int v){ 
    vis[v] = 1;
    for(auto it : adj[v]) 
        if (!vis[it]) 
            TSUtil(it); 
    Stack.push(v); 
} 

void TS(){ 
    for(int i = 1; i <= n; i++)
        if(!vis[i])
            TSUtil(i);
    while(Stack.empty() == 0){ 
        ind[Stack.top()] = no++; 
        Stack.pop(); 
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

bool Cycle(){
    for(int i = 1; i <= n; i++)
        if(CycleUtil(i))
            return 1;
    return 0;
}

void solve(){
    no = 0;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int f,u,v;
        cin>>f>>u>>v;
        if(f == 1) adj[u].pb(v);
        rem.pb({f,{u,v}});
    }
    if(Cycle() == 0){
        for(int i = 1; i <= n; i++) vis[i] = 0;
        TS();
        deb1("YES")
        for(auto it : rem){
            if(it.f == 1){
                deb2(it.s.f,it.s.s)
                continue;
            }
            if(ind[it.s.s] > ind[it.s.f]) deb2(it.s.f,it.s.s)
            else deb2(it.s.s,it.s.f)
        }
    }
    else deb1("NO")
    for(int i = 1; i <= n; i++){
        adj[i].clear();
        vis[i] = 0;
        ind[i] = 0;
        rec[i] = 0;
    }
    rem.clear();
}

int main(){
    fastio;
    cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
}