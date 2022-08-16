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
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const int   N    =  1e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test=1,n,m,dist[N],no[2][N],vis[N];
vll adj[N];

void bfs(){
    mset(dist,-1);
    queue <int> q;
    q.push(n);
    dist[n] = 0;
    while(q.size()){
        int x = q.front(); q.pop();
        for(auto it : adj[x]){
            if(dist[it] == -1){
                dist[it] = dist[x]+1;
                q.push(it);
            }
        }
    }
}

void bfs1(int x, int f){
    mset(vis,0);
    queue <int> q;
    q.push(x);
    while(q.size()){
        x = q.front(); q.pop();
        if(vis[x] == 1) continue;
        vis[x] = 1;
        for(auto it : adj[x]){
            if(dist[it] == dist[x]+1*f){
                int ind = (f==-1)? 0:1;
                no[ind][it] += no[ind][x];
                q.push(it);
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    for(int i = 1; i <= m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bfs();
    no[0][1] = 1, no[1][n] = 1;
    bfs1(1,-1);
    bfs1(n,+1);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        int x = (i==1 || i==n)? 1:2;
        ans = max(ans,no[0][i]*no[1][i]*x);
    }
    deb1((ld)ans/no[0][n]);
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