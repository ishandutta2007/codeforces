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
typedef  pair<ll, ll>          pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  6e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  1e16;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, q, a[N];

struct NODE{
	ll f, l, fs, ls, ans, sz;
	NODE(): f(0), l(0), fs(0), ls(0), ans(0), sz(0) {}
	NODE(int x): f(x), l(x), fs(1), ls(1), ans(1), sz(1) {}
};

NODE tree[4*N+8];

NODE combine(NODE a, NODE b){
	if (a.f == 0) return b;
	if (b.f == 0) return a;
	NODE c;
	c.f = a.f;
	c.l = b.l;
	c.ans = a.ans + b.ans;
	c.sz = a.sz + b.sz;
	if (b.sz == b.ls) {
		if (a.l <= b.f) {
			c.ls = a.ls + b.ls;
			c.ans += a.ls * b.fs;
		} else {
			c.ls = b.ls;
		}
	} else {
		if (a.l <= b.f) {
			c.ans += a.ls * b.fs;
		}
		c.ls = b.ls;
	}

	if (a.sz == a.fs) {
		if (a.l <= b.f) {
			c.fs = a.fs + b.fs;
		} else {
			c.fs = a.fs;
		}
	} else {
		c.fs = a.fs;
	}
	// deb3(a.ans, b.ans, c.ans)
	return c;
}

void build(int node, int start, int end){
	if(start == end){
		tree[node] = NODE(a[start]);
		// deb1(a[start])
	}
	else{
		int mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = combine(tree[2*node], tree[2*node+1]);
	}
}

void update(int node, int start, int end, int idx, ll val){
	if(start == end){
		tree[node] = NODE(val);
	}
	else{
		int mid = (start + end) / 2;
		if(start <= idx and idx <= mid)
			update(2*node, start, mid, idx, val);
		else
			update(2*node+1, mid+1, end, idx, val);
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

void solve() {
	cin >> n >> q;

	for (int i = 1; i <= n; i++) cin >> a[i];
	build (1, 1, n);
	
	while (q--) {
		int x, y, z; cin >> x >> y >> z;
		if (x == 1) {
			update(1, 1, n, y, z);
		} else {
			NODE Q = query(1, 1, n, y, z);
			deb1(Q.ans)
		}
	}
}

int main() {
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}