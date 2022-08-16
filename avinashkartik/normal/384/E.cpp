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
#define  debv(a)        for(auto it: a)cout<<it<<" "<<endl;
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
const ll   M     =  1e8;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, q, a[N], tin[N], tout[N], t = 0, ind[N], depth[N];
set <pll> seven, sodd;
vll adj[N], even, odd;

ll tree[N][2] = {};

void update(int idx, int val, int f){ 
    idx++;
    while(idx <= n+1){ 
        tree[idx][f] += val;
        idx += idx & (-idx); 
    } 
} 

ll query(int idx, int f){
    idx++;
    ll sum = 0;
    while(idx > 0){ 
        sum += tree[idx][f];
        idx -= idx & (-idx); 
    } 
    return sum; 
}

void dfs(int x, int p, int d){
    depth[x] = d;
    if(d&1){
        odd.pb(x);
        sodd.insert({t,x});
    }
    else{
        even.pb(x);
        seven.insert({t,x});
    }
    tin[x] = t++;
    for(auto it : adj[x]){
        if(it == p) continue;
        dfs(it,x,d+1);
    }
    tout[x] = t++;
}

void solve(){
    cin>>n>>q;
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i < n; i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
    }
    dfs(1,0,0);
    sodd.insert({t,n+1}); ind[n+1] = sodd.size();
    seven.insert({t,n+2}); ind[n+2] = seven.size();
    for(int i = 0; i < odd.size(); i++) ind[odd[i]] = i;
    for(int i = 0; i < even.size(); i++) ind[even[i]] = i;
    for(int i = 1; i <= n; i++){
        if(depth[i]&1){
            update(ind[i],a[i],1);
            update(ind[i]+1,-a[i],1);
        }
        else{
            update(ind[i],a[i],0);
            update(ind[i]+1,-a[i],0);
        }
    }
    while(q--){
        int x,u,v;
        cin>>x;
        if(x == 2){
            cin>>v;
            if(depth[v]&1) deb1(query(ind[v],1))
            else deb1(query(ind[v],0))
        }
        else{
            cin>>v>>u;
            if(depth[v]&1) u = -u;
            pll p = *seven.lower_bound({tin[v],0}), q = *seven.lower_bound({tout[v]+1,0});
            update(ind[p.s],u,0);
            update(ind[q.s],-u,0);
            p = *sodd.lower_bound({tin[v],0}), q = *sodd.lower_bound({tout[v]+1,0});
            update(ind[p.s],-u,1);
            update(ind[q.s],u,1);
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