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
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

int n, d[N], prv = 0, ans = 0;
vll adj[N];
ll par[N], level[N];
ll st[N][LEVEL];

void dfs1(int x, int p, int dep){
	d[x] = INFi;
	for(auto it : adj[x]){
		if(it == p) continue;
		dfs1(it, x, dep + 1);
		d[x] = min(d[x], d[it]);
	}
	if(d[x] == INFi) d[x] = dep;
}

void findpar(ll x, ll p){
	par[x] = p;
	for(auto it : adj[x]){
		if(it == p) continue;
		level[it] = level[x] + 1;
		findpar(it, x);
	}
}
 
void clearall(){
	for(ll i = 0; i <= n; i++){
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

void dfs(int x, int p){
	if(x != 1) ans = max(ans, distance(prv, x));
	//if(x != 1) deb3(x, prv, distance(prv, x))
	prv = x;
	set <pll> s;
	set <pll, greater<>> t;
	for(auto it : adj[x]){
		if(it == p) continue;
		if(x == 1) s.insert({d[it], it});
		else t.insert({d[it], it});
	}
	if(x == 1){
		for(auto it : s){
			dfs(it.s, x);
		}
	} else {
		for(auto it : t){
			dfs(it.s, x);
		}
	}
}

void solve(){
	cin >> n;
	for(ll i = 0; i <= n; i++) adj[i].clear(), d[i] = 0;
	ans = prv = 0;
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	fillst();
	dfs1(1, 0, 0);
	dfs(1, 0);
	deb1(max(ans, distance(1, prv)))
}

int main(){
	GODSPEED;
	int test = 1;
	cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}