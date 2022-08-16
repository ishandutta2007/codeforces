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

const int  N     =  2e5+5;
const int  mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N)+1;

ll n, dp[N], ans[N];
vll adj[N], pre[N], suf[N];

void dfs(int x, int p){
	dp[x] = 1;
	pre[x].resize(adj[x].size());
	suf[x].resize(adj[x].size());
	for(int i = 0; i < adj[x].size(); i++){
		int it = adj[x][i];
		if(it == p) continue;
		dfs(it, x);
		dp[x] = (dp[x] * (dp[it] + 1)) % mod;
	}
	ll prv = 1;
	for(int i = 0; i < adj[x].size(); i++){
		int it = adj[x][i];
		if(it == p) pre[x][i] = prv;
		else pre[x][i] = (prv * (dp[it] + 1)) % mod;
		prv = pre[x][i];
	}
	prv = 1;
	for(int i = adj[x].size() - 1; i >= 0; i--){
		int it = adj[x][i];
		if(it == p) suf[x][i] = prv;
		else suf[x][i] = (prv * (dp[it] + 1)) % mod;
		prv = suf[x][i];
	}
}

void reroot(int x, int p, ll val){
	ans[x] = ((val + 1) * dp[x]) % mod;
	for(int i = 0; i < adj[x].size(); i++){
		int it = adj[x][i];
		if(it == p) continue;
		ll res = val + 1;
		if(i != 0) res *= pre[x][i-1];
		res %= mod;
		if(i != adj[x].size()-1) res *= suf[x][i+1];
		res %= mod;
		reroot(it, x, res);
	}
}

void solve(){
	cin >> n;
	for(int i = 2; i <= n; i++){
		int x; cin >> x;
		adj[x].pb(i);
		adj[i].pb(x);
	}
	dfs(1, 0);
	reroot(1, 0, 0);
	for(int i = 1; i <= n; i++) cout << ans[i] << " ";
	newl;
}

int main(){
	GODSPEED;
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}