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

ll test = 1, n, m, k, power[N], val[10][10], ans = 0, hsh;
vpll adj[N];

void rec(int ind, int v){
	if(ind == k+1){
		ans += (v == hsh);
		return;
	}
	for(int i = 0; i < ind; i++) rec(ind+1, (v+val[ind][i])%mod);
}

void solve(){
	cin >> n >> m >> k;
	power[0] = 1;
	for(int i = 1; i <= n; i++) power[i] = (power[i-1]*31)%mod;
	for(int i = 1; i <= m; i++){
		int u, v, w; cin >> u >> v >> w;
		adj[u].pb({w,v});
	}
	for(int i = 1; i <= n; i++) sort(all(adj[i]));
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < adj[i].size(); j++){
			ll x = adj[i][j].s;
			val[adj[i].size()][j] = (val[adj[i].size()][j] + x*power[x])%mod;
		}
	}
	for(int i = 1; i <= n; i++) hsh = (hsh + i*power[i])%mod;
	rec(1,0);
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