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

const ll   N     =  5e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

struct NODE {
	ll ans, lazy;
	NODE(): ans(INFi), lazy(0) {}
};

NODE tree[4 * N + 8];

NODE combine(NODE a, NODE b) {
	NODE c;
	c.ans = min(a.ans, b.ans);
	return c;
}

void build(int node, int start, int end) {
	tree[node] = NODE();
	if (start == end) {
		tree[node].ans = 0;
	}
	else {
		int mid = (start + end) / 2;
		build(2 * node, start, mid);
		build(2 * node + 1, mid + 1, end);
		tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
	}
}

void pushlazy(int start, int end, int node) {
	if (tree[node].lazy == 0) return;
	tree[node].ans += tree[node].lazy;
	if (start != end) {
		tree[node * 2].lazy += tree[node].lazy;
		tree[node * 2 + 1].lazy += tree[node].lazy;
	}
	tree[node].lazy = 0;
}

void update(int node, int start, int end, int l, int r, ll val) {
	pushlazy(start, end, node);
	if (start > end or start > r or end < l)
		return;
	if (start >= l and end <= r) {
		tree[node].lazy += val;
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
	if (l <= start and end <= r) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	NODE p1 = query(2 * node, start, mid, l, r);
	NODE p2 = query(2 * node + 1, mid + 1, end, l, r);
	return combine(p1, p2);
}

ll n, a[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort (a + 1, a + n + 1);
	build(1, 1, n);
	update(1, 1, n, n, n, 1);
	int l = ceil(log2(n));
	ll ans = (1 << l) - n + 2;
	for (int i = n - 1; i >= 1; i--) {
		if (a[i] != a[i + 1]) {
			int v = n - i;
			int l = ceil(log2(v));
			update(1, 1, n, i, i, (1 << l) - v);
			int li = ceil(log2(i));
			ll res = query(1, 1, n, i + 1, n).ans;
			assert(res >= 0);
			ans = min(ans, (1 << li) - i + res);
			if (a[i + 1] - a[i] != 1) {
				int li = ceil(log2(i));
				ans = min(ans, (ll)(1 << l) - v + (1 << li) - i + 1);
			}
		} else {
			update(1, 1, n, i, i, INFi);
		}
		for (int j = 1; i + j <= n; j *= 2) {
			update(1, 1, n, i + j, i + j, j);
		}
		update(1, 1, n, i + 1, n, -1);
	}
	deb1(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}