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
 
const ll   N     =  1e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1,n,p,a[N],c[N],root=0,dp[N];
vll adj[N];

void inc(int x, int v){
    if(a[x] >= v) a[x]++;
    for(auto it : adj[x]){
        inc(it,v);
    }
}

void dfs(int x){
    for(auto it : adj[x]){
        dfs(it);
        dp[x] += dp[it];
    }
    if(c[x] > dp[x]){
        cout<<"NO"<<endl;
        exit(0);
    }
    int sz = dp[x];
    dp[x]++;
    inc(root,c[x]+1);
    a[x] = c[x]+1;
}

void solve(){
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>p>>c[i];
        adj[p].pb(i);
        if(p == 0) root = i;
    }
    dfs(root);
    cout<<"YES"<<endl;
    for(int i = 1; i <= n; i++) cout<<a[i]<<" ";
    cout<<endl;
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