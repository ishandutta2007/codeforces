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

const ll   N     =  3e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

ll test = 1, n, m, a[N], dist[N];
ll par[N], level[N];
ll st[N][LEVEL];
vll adj[N];

void findpar(ll x, ll p){
	par[x] = p;
	for(auto it : adj[x]){
		if(it == p) continue;
		level[it] = level[x] + 1;
		findpar(it,x);
	}
}
 
void clearall(){
	for(ll i = 0; i < N; i++){
		par[i] = -1;
		level[i] = -1;
		for(ll j = 0; j < LEVEL; j++) st[i][j] = -1;
	}
}
 
void fillst(){
	clearall();
	ll i,j;
	level[1] = 0;
	findpar(1,0);
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

void msbfs(){
	queue <ll> q;
	for(int i = 1; i <= n; i++) dist[i] = (a[i] == 0)? -1 : 0;
	for(int i = 1; i <= n; i++) if(a[i] == 1) q.push(i);
	while(q.size()){
		int x = q.front(); q.pop();
		for(auto it : adj[x]){
			if(dist[it] == -1){
				dist[it] = dist[x]+1;
				q.push(it);
			}
		}
	}
}

int distance(int u, int v){
	return level[u] + level[v] - 2*level[lca(u,v)];
}

void solve(){
	vpll q[N];
	cin>>n>>m;
	for(int i = 1; i < n; i++){
		int u, v; cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	fillst();
	for(int i = 1; i <= m; i++){
		int x, y; cin>>x>>y;
		q[i/320].pb({x,y});
	}
	a[1] = 1;
	for(int i = 0; i < 320; i++){
		msbfs();
		vll v;
		for(auto it : q[i]){
			if(it.f == 1) v.pb(it.s), a[it.s] = 1;
			else{
				int ans = dist[it.s];
				for(auto to : v) ans = min(ans,distance(it.s,to));
				deb1(ans)
			}
		}
	}
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