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

const int  N     =  3e5+5;
const int  mod   =  1e9+9;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N)+1;

ll n, q, a[N], fa[N], fb[N], prea[N], preb[N], cura, curb;

struct NODE{
	ll v, len;
	NODE() : v(), len() {}
	NODE(ll val) : v(val), len(1) {}
};

NODE tree[4*N+8];
pll lazy[4*N+8];

ll fib(ll a, ll b, ll n){
	return (fa[n]*a + fb[n]*b)%mod;
}

ll sum(ll a, ll b, ll n){
	return (prea[n]*a + preb[n]*b)%mod;
}

NODE combine(NODE a, NODE b){
	NODE c;
	c.v = (a.v + b.v)%mod;
	c.len = a.len + b.len;
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
	if(lazy[node].f + lazy[node].s == 0) return;
	tree[node].v = (tree[node].v + sum(lazy[node].f, lazy[node].s, tree[node].len))%mod;
	if(start != end){
		lazy[node*2].f = (lazy[node*2].f + lazy[node].f)%mod;
		lazy[node*2].s = (lazy[node*2].s + lazy[node].s)%mod;
		lazy[node*2+1].f = (lazy[node*2+1].f + fib(lazy[node].f, lazy[node].s, tree[node*2].len + 1))%mod;
		lazy[node*2+1].s = (lazy[node*2+1].s + fib(lazy[node].f, lazy[node].s, tree[node*2].len + 2))%mod;
	}
	lazy[node] = {0, 0};
}

void update(int node, int start, int end, int l, int r){
	pushlazy(start, end, node);
	if(start > end or start > r or end < l)
		return;
	if(start >= l and end <= r){
		lazy[node].f = (lazy[node].f + cura)%mod;
		lazy[node].s = (lazy[node].s + curb)%mod;
		pushlazy(start, end, node);
		ll ca = cura, cb = curb;
		cura = fib(ca, cb, tree[node].len + 1);
		curb = fib(ca, cb, tree[node].len + 2);
		return;
	}
	int mid = (start + end) / 2;
	update(node*2, start, mid, l, r);
	update(node*2 + 1, mid + 1, end, l, r);
	tree[node] = combine(tree[2*node], tree[2*node+1]);
}

NODE query(int node, int start, int end, int l, int r){
	if(start > end or start > r or end < l)
		return NODE(0);
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
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> a[i];
	fa[1] = prea[1] = 1;
	fb[1] = preb[1] = fa[2] = 0;
	fb[2] = preb[2] = prea[2] = 1;
	for(int i = 3; i <= n; i++){
		fa[i] = (fa[i-1] + fa[i-2])%mod;
		fb[i] = (fb[i-1] + fb[i-2])%mod;
		prea[i] = (prea[i-1] + fa[i])%mod;
		preb[i] = (preb[i-1] + fb[i])%mod;
	}
	build(1, 1, n);
	for(int i = 1; i <= q; i++){
		ll l, r, x; cin >> x >> l >> r;
		if(x == 1){
			cura = curb = 1;
			update(1, 1, n, l, r);
		} else {
			deb1(query(1, 1, n, l, r).v)
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