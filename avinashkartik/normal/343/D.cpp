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

const int  N     =  5e5+5;
const int  mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N)+1;

ll n, q, in[N], out[N], par[N], t = 0;
vll flat, adj[N];

int tree[4*N+8], lazy[4*N+8];

void pushlazy(int start, int end, int node){
	if(lazy[node] == -1) return;
	tree[node] = lazy[node];
	if(start != end){
		lazy[node*2] = lazy[node];
		lazy[node*2+1] = lazy[node];
	}
	lazy[node] = -1;
}

void update(int node, int start, int end, int l, int r, int val){
	pushlazy(start, end, node);
	if(start > end or start > r or end < l)
		return;
	if(start >= l and end <= r){
		lazy[node] = val;
		pushlazy(start, end, node);
		return;
	}
	int mid = (start + end) / 2;
	update(node*2, start, mid, l, r, val);
	update(node*2 + 1, mid + 1, end, l, r, val);
	tree[node] = min(tree[2*node],tree[2*node+1]);
}

int query(int node, int start, int end, int l, int r){
	if(start > end or start > r or end < l)
		return 2;
	pushlazy(start, end, node);
	if(l <= start and end <= r)
		return tree[node];
	int mid = (start + end) / 2;
	int p1 = query(2*node, start, mid, l, r);
	int p2 = query(2*node+1, mid+1, end, l, r);
	return min(p1, p2);
}

void dfs(int x, int p){
	par[x] = p;
	flat.pb(t);
	in[x] = t++;
	for(auto it : adj[x]){
		if(it == p) continue;
		dfs(it, x);
	}
	out[x] = t++;
}

void solve(){
	mset(lazy, -1);
	cin >> n;
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1, 0);
	cin >> q;
	for(int i = 1; i <= q; i++){
		int x, y; cin >> x >> y;
		if(x == 1){
			int l = lower_bound(all(flat), in[y]) - flat.begin();
			int r = lower_bound(all(flat), out[y]) - flat.begin() - 1;
			if(query(1, 0, n, l, r) == 0 and y != 1){
				int ind = lower_bound(all(flat), in[par[y]]) - flat.begin();
				update(1, 0, n, ind, ind, 0);
			}
			update(1, 0, n, l, r, 1);
		} else if(x == 2){
			int l = lower_bound(all(flat), in[y]) - flat.begin();
			update(1, 0, n, l, l, 0);
		} else{
			int l = lower_bound(all(flat), in[y]) - flat.begin();
			int r = lower_bound(all(flat), out[y]) - flat.begin() - 1;
			int mn = query(1, 0, n, l, r);
			deb1(mn)
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