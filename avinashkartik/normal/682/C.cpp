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
 
const ll   N     =  5e5+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1,n,m,a[N],vis[N],ans = 0;
vpll adj[N];

void dfs(int x, int par, ll d, ll m){
	if(a[x] < d-m){
		vis[x] = 1;
		return;
	}
	m = min(d,m);
	for(auto it : adj[x]){
		if(it.f != par)
			dfs(it.f,x,d+it.s,m);
	}
}

void cnt(int x, int par){
	ans++;
	for(auto it : adj[x]){
		if(it.f != par and vis[it.f] == 0)
			cnt(it.f,x);
	}
}

void solve(){
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	for(int i = 2; i <= n; i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb({i,v});
    }
    dfs(1,0,0,0);
    cnt(1,0);
    deb1(n-ans)
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
}