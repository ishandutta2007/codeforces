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

const ll   N     =  5e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

ll test = 1, n, m, depth[N], par[N], deg[N];
vll adj[N];

void dfs(int x){
	for(auto it : adj[x]){
		if(depth[it] == -1){
			depth[it] = depth[x] + 1;
			par[it] = x;
			deg[x]++;
			dfs(it);
		}
	}
}

void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		deg[i] = 0;
		depth[i] = -1;
		adj[i].clear();
	}
	for(int i = 1; i <= m; i++){
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	depth[1] = 0;
	dfs(1);
	set <int> s;
	for(int i = 1; i <= n; i++){
		if(depth[i] >= (n+1)/2){
			deb1("PATH")
			int x = i;
			deb1(depth[i]+1)
			while(x){
				cout << x << " ";
				x = par[x];
			}
			newl;
			return;
		}
		if(deg[i] == 0) s.insert(i);
	}
	vpll ans;
	while(s.size() > 1){
		int p,q;
		auto it = s.begin();
		p = (*it); it++;
		q = (*it);
		s.erase(p); s.erase(q);
		deg[par[p]]--, deg[par[q]]--;
		if(deg[par[p]] == 0) s.insert(par[p]);
		if(deg[par[q]] == 0) s.insert(par[q]);
		ans.pb({p,q});
	}
	deb1("PAIRING")
	deb1(ans.size())
	for(auto it : ans) deb2(it.f,it.s)
}

int main(){
	GODSPEED;
	cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}