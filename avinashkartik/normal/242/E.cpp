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

const ll   N     =  2e5 + 5;
const ll   mod   =  998244353 ;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

int n, q, a[N];

struct NODE {
	ll a[20], l[20];
	NODE() {
		for (int i = 0; i < 20; i++) a[i] = l[i] = 0;
	}
};

NODE tree[4 * N + 8];

NODE combine(NODE a, NODE b) {
	NODE c;
	for (int i = 0; i < 20; i++) c.a[i] = a.a[i] + b.a[i];
	return c;
}

void build(int node, int start, int end) {
	if (start == end) {
		tree[node] = NODE();
		for (int i = 0; i < 20; i++) {
			tree[node].a[i] = (a[start] >> i) & 1;
		}
	} else {
		int mid = (start + end) / 2;
		build(2 * node, start, mid);
		build(2 * node + 1, mid + 1, end);
		tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
	}
}

void pushlazy(int start, int end, int node) {
	int f = 0;
	for (int i = 0; i < 20; i++) {
		f |= tree[node].l[i];
		if (tree[node].l[i]) {
			tree[node].a[i] = (end - start + 1 - tree[node].a[i]);
		}
	}
	if (f == 0) return;
	if (start != end) {
		for (int i = 0; i < 20; i++) {
			tree[2 * node].l[i] ^= tree[node].l[i];
			tree[2 * node + 1].l[i] ^= tree[node].l[i];
		}
	}
	for (int i = 0; i < 20; i++) tree[node].l[i] = 0;
}

void update(int node, int start, int end, int l, int r, ll val) {
	pushlazy(start, end, node);
	if (start > end or start > r or end < l)
		return;
	if (start >= l and end <= r) {
		for (int i = 0; i < 20; i++) {
			tree[node].l[i] ^= ((val >> i) & 1);
		}
		pushlazy(start, end, node);
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, l, r, val);
	update(node * 2 + 1, mid + 1, end, l, r, val);
	tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
}

NODE query(int node, int start, int end, int l, int r) {
	if (start > end or start > r or end < l)
		return NODE();
	pushlazy(start, end, node);
	if (l <= start and end <= r)
		return tree[node];
	int mid = (start + end) / 2;
	NODE p1 = query(2 * node, start, mid, l, r);
	NODE p2 = query(2 * node + 1, mid + 1, end, l, r);
	return combine(p1, p2);
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	cin >> q;
	while (q--) {
		int x, y, l, r; cin >> x >> l >> r;
		if (x == 1) {
			NODE ans = query(1, 1, n, l, r);
			ll res = 0;
			for (int i = 0; i < 20; i++) res += (1 << i) * ans.a[i];
			deb1(res)
		} else {
			cin >> y;
			update(1, 1, n, l, r, y);
		}
	}
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}