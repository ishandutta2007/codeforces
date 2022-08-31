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
 
const ll   N     =  2005;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, a[N], vis[N], d, ans=0;
vll adj[N];

ll dfs(int x,int mn, int root){
    if(a[x] < mn || (a[x] == mn && x < root) || mn+d < a[x]) return 0;
    vis[x] = 1;
    ll res = 1;
    for(auto it : adj[x]){
        if(vis[it] == 0) res = (res*(dfs(it,mn,root)+1))%mod;
    }
    return res;
}

void solve(){
    cin>>d>>n;
    for(int i = 1; i <= n; i++) cin>>a[i];
    int res=0,u,v;
    for(int i = 0; i < n-1; i++){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 1; i <= n; i++){
        mset(vis,0);
        ans = (ans+dfs(i,a[i],i))%mod;
        //deb1(ans)
    }
    deb1(ans);
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