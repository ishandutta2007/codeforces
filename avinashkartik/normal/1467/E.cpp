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

const ll   N     =  4e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

ll n, k, q, a[N], b[N];
ll par[N], level[N], sz[N];
ll st[N][LEVEL];
vll flat, adj[N];

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

ll tree[4*N+8], lazy[4*N+8], in[N], out[N], t = 0;

void pushlazy(int start, int end, int node){
	if(lazy[node] == 0) return;
	tree[node] += (end - start + 1) * lazy[node];
	if(start != end){
		lazy[node*2] += lazy[node];
		lazy[node*2+1] += lazy[node];
	}
	lazy[node] = 0;
}

void update(int node, int start, int end, int l, int r, int val){
	pushlazy(start, end, node);
	if(start > end or start > r or end < l)
		return;
	if(start >= l and end <= r){
		lazy[node] += val;
		pushlazy(start, end, node);
		return;
	}
	int mid = (start + end) / 2;
	update(node*2, start, mid, l, r, val);
	update(node*2 + 1, mid + 1, end, l, r, val);
	tree[node] = tree[2*node] + tree[2*node+1];
}

ll query(int node, int start, int end, int l, int r){
	if(start > end or start > r or end < l)
		return 0;
	pushlazy(start, end, node);
	if(l <= start and end <= r)
		return tree[node];
	int mid = (start + end) / 2;
	ll p1 = query(2*node, start, mid, l, r);
	ll p2 = query(2*node+1, mid+1, end, l, r);
	return p1 + p2;
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
	cin >> n;
	fillst();
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i < n; i++){
		ll x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(1, 0);
	map <ll, ll> m;
	for(int i = 1; i <= n; i++){
		if(m[a[i]]){
			int v = lca(m[a[i]], i);
			if(v == i || v == m[a[i]]){
				update(1, 1, n, 1, n, 1);
				int l = lower_bound(all(flat), in[v]) - flat.begin();
				int r = lower_bound(all(flat), out[v]) - flat.begin() - 1;
				update(1, 1, n, l, r, 1);
				int u = (v == i)? m[a[i]] : i;
				l = lower_bound(all(flat), in[u]) - flat.begin();
				r = lower_bound(all(flat), out[u]) - flat.begin() - 1;
				update(1, 1, n, l, r, 1);
				m[a[i]] = v;
				l = lower_bound(all(flat), in[v]) - flat.begin();
				update(1, 1, n, l, l, 1);
			} else {
				int v = m[a[i]], u = i;
				int l = lower_bound(all(flat), in[v]) - flat.begin();
				int r = lower_bound(all(flat), out[v]) - flat.begin() - 1;
				//deb2(l, r)
				update(1, 1, n, l, r, 1);
				l = lower_bound(all(flat), in[u]) - flat.begin();
				r = lower_bound(all(flat), out[u]) - flat.begin() - 1;
				update(1, 1, n, l, r, 1);
				m[a[i]] = lca(u, v);
			}
		} else{
			m[a[i]] = i;
		}
	}
	ll ct = 0;
	for(int i = 1; i<= n; i++){
		ct += (query(1, 1, n, i, i) == 0);
	}
	deb1(ct)
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