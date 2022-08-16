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

const ll   N     =  3e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

ll test = 1, n, m, q, a[N], dp[N], ans = 0;
vpll adj[N];

void dfs(ll x, ll p){
	dp[x] = a[x];
	vll v;
	for(auto it : adj[x]){
		if(it.f == p) continue;
		dfs(it.f,x);
		v.pb({max(0ll,dp[it.f]-it.s)});
	}
	sort(all(v),greater<>());
	if(v.size() > 1) ans = max(ans,v[0]+v[1]+dp[x]);
	if(v.size()) dp[x] += v[0];
	ans = max(ans,dp[x]);
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i < n; i++){
		int u, v, w; cin >> u >> v >> w;
		adj[u].pb({v,w});
		adj[v].pb({u,w});
	}
	dfs(1,0);
	deb1(ans)
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