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

const ll   N     =  2e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

ll n, a[N], mx[N], sz[N];
vll adj[N];

void dfs(int x, int p){
	sz[x] = 1, mx[x] = 0;
	for(auto it : adj[x]){
		if(it == p) continue;
		dfs(it, x);
		sz[x] += sz[it];
		mx[x] = max(mx[x], sz[it]);
	}
	mx[x] = max(mx[x], n-sz[x]);
}

void solve(){
	cin >> n;
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1, 0);
	mx[0] = n+1;
	int ans = 0, u = 0;
	for(int i = 1; i <= n; i++){
		if(mx[i] < mx[ans]) ans = i, u = 0;
		else if(mx[i] == mx[ans]) u = i;
	}
	if(u == 0){
		deb2(1, adj[1][0])
		deb2(1, adj[1][0])
	} else{
		if(adj[ans][0] != u){
			deb2(ans, adj[ans][0])
			deb2(u, adj[ans][0])
		} else{
			deb2(ans, adj[ans][1])
			deb2(u, adj[ans][1])
		}
	}
	for(int i = 1; i <= n; i++) adj[i].clear();
}

int main(){
	GODSPEED;
	int test = 1;
	cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}