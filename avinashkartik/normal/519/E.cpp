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

ll n, m;
ll par[N], level[N], sz[N];
ll st[N][LEVEL];
vll adj[N];

ll tree[N] = {};

void findpar(ll x, ll p){
	par[x] = p;
	sz[x] = 1;
	for(auto it : adj[x]){
		if(it == p) continue;
		level[it] = level[x] + 1;
		findpar(it, x);
		sz[x] += sz[it];
	}
}
 
void clearall(){
	for(ll i = 0; i < N; i++){
		par[i] = -1;
		level[i] = -1;
		for(ll j = 0; j < LEVEL; j++) st[i][j] = -1;
	}
}
 
void fillst(int root = 1){
	clearall();
	ll i, j;
	level[root] = 0;
	findpar(root, 0);
	for(j = 0; j < LEVEL; j++){
		for(i = 1; i <= n; i++){
			if(j == 0) st[i][j] = par[i];
			if(st[i][j-1] != -1) st[i][j] = st[st[i][j-1]][j-1];
		}
	}
}
 
ll lca(ll x, ll y){
	if(level[y] < level[x])
		swap(x,y);
	ll diff = level[y]-level[x];
	for(ll i = 0;i < LEVEL; i++){
		// Checks all set bits in diff
		if((diff>>i)&1){
			y = st[y][i];
		}
	}
	if(x == y)
		return x;
	for(ll i = LEVEL-1; i >= 0; i--){
		// First highest of x and y that are unequal
		if(st[x][i] != -1 && st[x][i] != st[y][i]){
			x = st[x][i];
			y = st[y][i];
		}
	}
	return st[x][0];
}

int distance(int u, int v){
	return level[u] + level[v] - 2*level[lca(u,v)];
}

int kth(int x, int k){
	for(int i = LEVEL - 1; i >= 0; i--){
		if(k >= (1 << i)){
			x = st[x][i];
			k -= (1 << i);
		}
	}
	return x;
}

void solve(){
	cin >> n;
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	fillst();
	cin >> m;
	while(m--){
		int x, y;
		cin >> x >> y;
		if(x == y){
			deb1(n)
		} else if(level[x] == level[y]){
			int d = distance(x, y);
			int l = lca(x, y);
			deb1(n - sz[kth(x, d / 2 - 1)] - sz[kth(y, d / 2 - 1)])
		} else {
			int d = distance(x, y) + 1;
			if(level[x] < level[y]) swap(x, y);
			if(d % 2) deb1(sz[kth(x, d / 2)] - sz[kth(x, d / 2 - 1)])
			else deb1(0)
		}
	}
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