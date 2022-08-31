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
 
const ll   N     =  5e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, m, a[N], u[N], v[N], vis[N] = {}, d[N];
vll adj[N];
vpll ord;

void solve(){
    cin>>n>>m;
    for(int i = 1; i <= m; i++){
        cin>>u[i]>>v[i];
        adj[u[i]].pb(v[i]);
        adj[v[i]].pb(u[i]);
    }
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(adj[i].size()+1 < a[i]){
            deb1(-1)
            return;
        }
        ord.pb({a[i],i});
    }
    for(int i = 1; i <= m; i++){
        if(a[u[i]] == a[v[i]]){
            deb1(-1)
            return;
        }
    }
    sort(ord.begin(), ord.end());
    vll ans;
    for(int i = 0; i < n; i++){
        ll m = 0, p[ord[i].f+1];
        for(auto it : adj[ord[i].s]){
            if(vis[it] == 1){
                d[a[it]] = 1;
            }
        }
        for(int j = 1; j < ord[i].f; j++){
            if(d[j] == 0){
                deb1(-1)
                return;
            }
        }
        for(int j = 1; j < ord[i].f; j++) d[j] = 0;
        ans.pb(ord[i].s);
        vis[ord[i].s] = 1;
    }
    debv(ans)
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