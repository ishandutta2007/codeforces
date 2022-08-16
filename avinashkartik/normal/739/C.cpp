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

ll n, q, a[N];
string s;

struct NODE{
	ll len, prei, sufi, inc, pred, sufd, preb, sufb, f, l;
	NODE(): len(), prei(), sufi(), inc(), pred(), sufd(), preb(), sufb(), f(), l() {}
	NODE(int v): len(1), prei(1), sufi(1), inc(1), pred(1), sufd(1), preb(1), sufb(1), f(v), l(v) {}
};

NODE tree[4*N+8];
ll lazy[4*N+8];

NODE combine(NODE a, NODE b){
	NODE c;
	c.len = a.len + b.len;
	c.f = a.f;
	c.l = b.l;
	c.prei = a.prei;
	c.pred = a.pred;
	c.preb = a.preb;
	c.sufi = b.sufi;
	c.sufd = b.sufd;
	c.sufb = b.sufb;
	c.inc = max(a.inc, b.inc);
	if(a.l > b.f){
		if(a.pred == a.len) c.pred = a.pred + b.pred;
		if(b.sufi == b.len) c.sufi = a.sufi + b.sufi;
		if(a.preb == a.len) c.preb = a.preb + b.pred;
		if(b.sufi == b.len) c.sufb = a.sufb + b.sufi;
		c.inc = max(c.inc, a.sufb + b.pred);
	}
	if(a.l < b.f){
		if(a.prei == a.len) c.prei = a.prei + b.prei;
		if(b.sufd == b.len) c.sufd = a.sufd + b.sufd;
		if(b.sufb == b.len) c.sufb = a.sufd + b.sufb;
		if(a.prei == a.len) c.preb = a.prei + b.preb;
		c.inc = max(c.inc, a.sufd + b.preb);
	}
	c.preb = max({c.preb, c.prei, c.pred});
	c.sufb = max({c.sufb, c.sufi, c.sufd});
	c.inc = max({c.inc, c.preb, c.sufb});
	if(a.l != b.f) c.inc = max(c.inc, a.sufd + b.pred);
	return c;
}

void build(int node, int start, int end){
	if(start == end){
		tree[node] = NODE(a[start]);
	}
	else{
		int mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = combine(tree[2*node], tree[2*node+1]);
	}
}

void pushlazy(int start, int end, int node){
	if(lazy[node] == 0) return;
	tree[node].f += lazy[node];
	tree[node].l += lazy[node];
	if(start != end){
		lazy[node*2] += lazy[node];
		lazy[node*2+1] += lazy[node];
	}
	lazy[node] = 0;
}

void update(int node, int start, int end, int l, int r, ll val){
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
	tree[node] = combine(tree[2*node], tree[2*node+1]);
}

NODE query(int node, int start, int end, int l, int r){
	if(start > end or start > r or end < l)
		return NODE();
	pushlazy(start,end,node);
	if(l <= start and end <= r){
		return tree[node];
	}
	int mid = (start + end) / 2;
	NODE p1 = query(2*node, start, mid, l, r);
	NODE p2 = query(2*node+1, mid+1, end, l, r);
	return combine(p1, p2);
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	cin >> q;
	for(int i = 1; i <= q; i++){
		ll l, r, d; cin >> l >> r >> d;
		update(1, 1, n, l, r, d);
		deb1(tree[1].inc)
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