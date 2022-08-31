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

ll test=1,n,m,visited[N],recStack[N],M[N],M1[N];
vll adj[N],rev[N];

bool isCyclicUtil(int v){ 
    if(visited[v] == false){
        visited[v] = true; 
        recStack[v] = true; 
        for(auto it : adj[v]) { 
            if ( !visited[it] && isCyclicUtil(it) ) 
                return true; 
            else if (recStack[it]) 
                return true; 
        } 
  
    } 
    recStack[v] = false;
    return false; 
}

bool isCyclic(){
    for(int i = 1; i <= n; i++) 
        if(isCyclicUtil(i)) 
            return true; 
    return false; 
}

void assign(int x){
    M[x] = x;
    for(auto it : adj[x]){
        if(M[it] == 0) assign(it);
        M[x] = min(M[x],M[it]);
    }
}

void assign1(int x){
    M1[x] = x;
    for(auto it : rev[x]){
        if(M1[it] == 0) assign1(it);
        M1[x] = min(M1[x],M1[it]);
    }
}

void solve(){
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        rev[v].pb(u);
    }
    if(isCyclic() == 0){
        mset(visited,0);
        for(int i = 1; i <= n; i++)
            if(M[i] == 0)
                assign(i);
        for(int i = 1; i <= n; i++)
            if(M1[i] == 0)
                assign1(i);
        int ct = 0;
        for(int i = 1; i <= n; i++)
            if(M[i] == i && M1[i] == i) ct++;
        deb1(ct)
        for(int i = 1; i <= n; i++){
            if(M[i] == i && M1[i] == i) cout<<"A";
            else cout<<"E";
        }
    }
    else{
        cout<<-1<<endl;
    }
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
}