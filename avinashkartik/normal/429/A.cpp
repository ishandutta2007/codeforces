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

const int  N     =  1e5+5;
const int  mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N)+1;

ll test = 1, n, a[N], b[N];
vll adj[N], ans;

void dfs(int x, int p, int d, int o, int e){
	if(d){
		a[x] ^= o;
		if(a[x] != b[x]) o ^= 1, ans.pb(x);

	} else {
		a[x] ^= e;
		if(a[x] != b[x]) e ^= 1, ans.pb(x);
	}
	for(auto it : adj[x]){
		if(it == p) continue;
		dfs(it,x,(d+1)%2,o,e);
	}
}

void solve(){
	cin >> n;
	for(int i = 1; i < n; i++){
		int u,v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];	
	dfs(1,0,0,0,0);
	deb1(ans.size())
	for(auto it : ans) deb1(it)
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