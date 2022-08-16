#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
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
 
const int   N    =  1e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int test=1, n, m, p, depth[N], q[N][2], ans[N];
set <ll> s;
string t;
vll adj[N];
vpll v[N];

void dfs(int x, int par, int d){
    vpll bt;
    for(auto it : v[x]){
        if(s.find(it.f) != s.end()){
            bt.pb({it.f,depth[it.f]});
        }
        depth[it.f] = 0;
        s.insert(it.f);
    }
    for(auto it : adj[x]){
        dfs(it,x,d+1);
    }
    if(s.find(d) != s.end()){
        int ind = t[x] - 'a';
        depth[d] ^= (1<<ind);
    }
    for(auto it : v[x]){
        if(__builtin_popcount(depth[it.f]) < 2) ans[it.s] = 1;
        else ans[it.s] = 0;
        s.erase(it.f);
    }
    for(auto it : bt){
        depth[it.f] ^= it.s;
        s.insert(it.f);
    }
}

void solve(){
    cin>>n>>m;
    for(int i = 2; i <= n; i++) cin>>p, adj[p].pb(i);
    cin>>t;
    t = 'a'+t;
    for(int i = 1; i <= m; i++){
        int vi,hi;
        cin>>vi>>hi;
        v[vi].pb({hi,i});
        q[i][0] = vi;
        q[i][1] = hi;
    }
    dfs(1,0,1);
    for(int i = 1; i <= m; i++) ans[i] == 1? cout<<"Yes"<<endl:cout<<"No"<<endl;
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