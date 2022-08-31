#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first                 
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()           
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const int  N     =  1e6+5;
const int  mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N)+1;

ll test = 1, n, m;
vpll adj[N];
map <pll, pll> ind;

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
        for(auto i : adj[v]){
            ll to = i.f;
            ll len = i.s;
            if (d[v] + len == d[to]) p[to] = v;
            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
            	d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        if(i == s) continue;
        int u = i, v = p[i];
        if(u > v) swap(u,v);
        ans += ind[{u,v}].s;
    }
    deb1(ans)
    for(int i = 1; i <= n; i++){
        if(i == s) continue;
        int u = i, v = p[i];
        if(u > v) swap(u,v);
        cout << ind[{u,v}].f << " ";
    }
    newl;
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        ll u,v,w; cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
        if(u > v) swap(u,v);
        ind[{u,v}] = {i,w};
    }
    int u; cin >> u;
    dijkstra(u);
}

int main(){
    GODSPEED;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}