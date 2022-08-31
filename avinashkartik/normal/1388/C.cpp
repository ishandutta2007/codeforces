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

const ll   N     =  1e6+5;
const ll   mod   =  1e9;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, m, p[N], h[N], sz[N], f, pos[N], neg[N];
vll adj[N];

void dfs(int x, int par){
	sz[x] = p[x];
	ll ni = 0, pi = 0;
	for(auto it : adj[x]){
		if(it == par) continue;
		dfs(it,x);
		sz[x] += sz[it];
		pi += pos[it];
		ni += neg[it];
	}
	if(abs(h[x]) > sz[x]) f = 0;
	if((h[x]+2*mod)%2 != sz[x]%2) f = 0;
	pos[x] = (sz[x]+h[x])/2;
	neg[x] = (sz[x]-h[x])/2;
	if(pi > pos[x]) f = 0;
}

void solve(){
	f = 1;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> p[i];
	for(int i = 1; i <= n; i++) cin >> h[i];
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1,0);
	for(int i = 1; i <= n; i++) adj[i].clear();
	if(f) deb1("YES")
	else deb1("NO")
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