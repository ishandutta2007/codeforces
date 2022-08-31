#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
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
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()           
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  2e6+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int test = 1, n, dp[N], ans;
vll adj[N];

int calc(int x){
	vll v;
	for(auto it : adj[x]) v.pb(dp[it]);
	sort(all(v),greater<>());
	int ans = v[0]+1, sz = adj[x].size();
	if(v.size() > 1) ans += v[1];
	ans += max(0,sz-2);
	return ans;
}

int val(int x, int p){
	int mx = 0;
	for(auto it : adj[x]){
		if(it == p) continue;
		mx = max(mx,dp[it]);
	}
	int sz = adj[x].size();
	return mx+max(0,sz-2)+1;
}

void dfs(int x, int p){
	for(auto it : adj[x]){
		if(it == p) continue;
		dfs(it,x);
	}
	dp[x] = val(x,p);
}

void reroot(int x, int p){
	if(p != 0){
		dp[p] = val(p,x);
		ans = max(ans,calc(x));
	}
	for(auto it : adj[x]){
		if(it == p) continue;
		reroot(it,x);
	}
	if(p != 0){
		dp[x] = val(x,p);
	}
}

void solve(){
	cin>>n;
	for(int i = 1; i < n; i++){
		int u, v; cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1,0);
	ans = calc(1);
	reroot(1,0);
	deb1(ans)
	for(int i = 1; i <= n; i++) adj[i].clear();
}

int main(){
	GODSPEED;
	cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}