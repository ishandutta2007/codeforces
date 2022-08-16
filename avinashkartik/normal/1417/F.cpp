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
const ll   M     =  4e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, m, q, a[N], u[N], v[N], rem[N], X[N], Y[N];
int p[N], sz[N], l[N], r[N], ind[N];
vll adj[N];

struct NODE{
	int val, ind;
	NODE(): val(), ind() {}
	NODE(int v, int i): val(v), ind(i){}
};

NODE tree[4*N+8];

NODE combine(NODE a, NODE b){
	NODE c;
	c.val = max(a.val, b.val);
	if(c.val == a.val) c.ind = a.ind;
	else c.ind = b.ind;
	return c;
}

void build(int node, int p, int start, int end){
	if(start == end){
		tree[node] = NODE(a[adj[p][start-1]], start);
	}
	else{
		int mid = (start + end) / 2;
		build(2*node, p, start, mid);
		build(2*node+1, p, mid+1, end);
		tree[node] = combine(tree[2*node], tree[2*node+1]);
	}
}

void update(int node, int start, int end, int idx){
	if(start == end){
		tree[node] = NODE(0, idx);
	}
	else{
		int mid = (start + end) / 2;
		if(start <= idx and idx <= mid)
			update(2*node, start, mid, idx);
		else
			update(2*node+1, mid+1, end, idx);
		tree[node] = combine(tree[2*node], tree[2*node+1]);
	}
}

NODE query(int node, int start, int end, int l, int r){
	if(start > end or start > r or end < l)
		return NODE();
	if(l <= start and end <= r)
		return tree[node];
	int mid = (start + end) / 2;
	NODE p1 = query(2*node, start, mid, l, r);
	NODE p2 = query(2*node+1, mid+1, end, l, r);
	return combine(p1, p2);
}

void make(ll n){
	for(int i = 1; i <= n; i++){
		p[i] = i;
		sz[i] = 1;
		adj[i].pb(i);
	}
}

int find(ll x){
	return (p[x] == x)? x: p[x] = find(p[x]);
}

void merge(ll x, ll y){
	ll a = find(x);
	ll b = find(y);
	if(a != b){
		if(sz[a] >= sz[b]) swap(a,b);
		p[a] = b;
		sz[b] += sz[a];
		for(auto it : adj[a]) adj[b].pb(it);
		adj[a].clear();
	}
}

void solve(){
	cin >> n >> m >> q;
	make(n);
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++) cin >> u[i] >> v[i];
	for(int i = 1; i <= q; i++){
		cin >> X[i] >> Y[i];
		if(X[i] == 2) rem[Y[i]] = 1;
	}
	for(int i = 1; i <= m; i++){
		if(rem[i] == 1) continue;
		merge(u[i], v[i]);
	}
	for(int i = q; i >= 1; i--){
		if(X[i] == 2) merge(u[Y[i]], v[Y[i]]);
		else{
			int x = find(Y[i]);
			l[i] = adj[x].front(), r[i] = adj[x].back();
		}
	}
	for(int i = 2; i <= n; i++) merge(1, i);
	int p = find(1);
	for(int i = 0; i < n; i++) ind[adj[p][i]] = i+1;
	build(1, p, 1, n);
	for(int i = 1; i <= q; i++){
		if(X[i] == 2) continue;
		NODE c = query(1, 1, n, ind[l[i]], ind[r[i]]);
		if(c.ind) update(1, 1, n, c.ind);
		deb1(c.val)
	}
}

int main(){
	GODSPEED;
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}