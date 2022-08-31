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
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  1e6+8;
const ll   mod   =  998244353;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, m, a[N], vis[N];
set <pll, greater<pll>> s;
vpll adj[N];

void solve(){
    cin>>n>>m;
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].pb({y,i});
        adj[y].pb({x,i});
        a[x]--, a[y]--;
    }
    for(int i = 1; i <= n; i++) s.insert({a[i],i});
    vll ans;
    for(int i = 1; i <= n; i++){
        pll p = *s.begin();
        s.erase(p);
        if(p.f < 0){
            deb1("DEAD")
            return;
        }
        for(auto it : adj[p.s]){
            if(!vis[it.f]){
                s.erase({a[it.f],it.f});
                a[it.f]++;
                s.insert({a[it.f],it.f});
                ans.pb(it.s);
            }
        }
        vis[p.s] = 1;
    }
    deb1("ALIVE")
    reverse(ans.begin(), ans.end());
    assert(ans.size() == m);
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