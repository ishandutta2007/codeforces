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
 
const ll   N     =  1e3+5;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, m, dist[N][2];
vll adj[N], comp;
vpll ans;

void dfs(int x, int par, int f){
	dist[x][f] = dist[par][f]+1;
	for(auto it : adj[x]){
		if(it == par) continue;
		dfs(it,x,f);
	}
}

pll diameter(int x){
	mset(dist,-1);
	dfs(x,0,0);
	int mx = 0, v = x, u = 0;
	for(int i = 1; i <= n; i++){
		if(dist[i][0] >= mx){
			mx = dist[i][0];
			v = i;
		}
	}
	mset(dist,-1);
	dfs(v,0,0);
	mx = 0, u = v;
	for(int i = 1; i <= n; i++){
		if(dist[i][0] >= mx){
			mx = dist[i][0];
			u = i;
		}
	}
	return {v,u};
}

int centre(int x){
	pll p = diameter(x);
	int v = p.f, u = p.s;
	dfs(u,0,1);
	int dia = dist[u][0];
	if(u == v) return x;
	for(int i = 1; i <= n; i++){
		if(dist[i][0] == dia/2 and dist[i][1] == dia - dia/2)
			return i;
	}
}

void solve(){
	cin>>n>>m;
	for(int i = 1; i <= m; i++){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	mset(dist,-1);
	for(int i = 1; i <= n; i++){
		if(dist[i][0] == -1){
			comp.pb(i);
			dfs(i,0,0);
		}
	}
	int st = 1, mx = 0;
	for(auto it : comp){
		pll p = diameter(it);
		if(dist[p.s][0] > mx){
			mx = dist[p.s][0];
			st = it;
		}
	}
	for(int i = 0; i < comp.size(); i++){
		if(st == comp[i]) continue;
		int v = centre(st), u = centre(comp[i]);
		ans.pb({u,v});
		adj[u].pb(v);
		adj[v].pb(u);
	}
	pll p = diameter(1);
	deb1(dist[p.s][0])
	for(auto it : ans) deb2(it.f,it.s)
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