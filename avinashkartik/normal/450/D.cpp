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
typedef  unordered_map<ll,pll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  1e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, m, k, train[N];
vpll adj[N];

void dijkstra(int s) {
    vll d(n+1, INF);
    vll p(n+1, -1);
    d[s] = 0;
    set<pll> q;
    ll ct = 0;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->s;
        q.erase(q.begin());
        if(d[v] == train[v]+1){
            d[v] = train[v];
            ct++;
        }
        for(auto i : adj[v]){
            ll to = i.f;
            ll len = i.s;
            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
            	d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
    deb1(k-ct)
}

void solve(){
    cin>>n>>m>>k;
    for(int i = 1; i <= m; i++){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    for(int i = 1; i <= n; i++) train[i] = INF;
    for(int i = 1; i <= k; i++){
        ll s,y;
        cin>>s>>y;
        adj[1].pb({s,y+1});
        train[s] = min(train[s],y);
    }
    dijkstra(1);
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