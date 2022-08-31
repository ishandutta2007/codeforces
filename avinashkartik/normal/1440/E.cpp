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
typedef  pair<ll, ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  2e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, q, a[N];

struct NODE {
	ll mx, mn, sum;
	NODE() : mx(), mn(), sum() {}
	NODE(ll x) : mx(x), mn(x), sum(x) {}
};

NODE tree[4 * N + 8];
ll lazy[4 * N + 8];

NODE combine(NODE a, NODE b) {
	NODE c;
	c.mx = max(a.mx, b.mx);
	c.mn = min(a.mn, b.mn);
	c.sum = a.sum + b.sum;
	return c;
}

void build(int node, int start, int end) {
	if (start == end) {
		tree[node] = NODE(a[start]);
	}
	else {
		int mid = (start + end) / 2;
		build(2 * node, start, mid);
		build(2 * node + 1, mid + 1, end);
		tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
	}
}

void pushlazy(int start, int end, int node) {
	if (lazy[node] == 0) return;
	tree[node].sum = (end - start + 1) * lazy[node];
	tree[node].mx = tree[node].mn = lazy[node];
	if (start != end) {
		lazy[node * 2] = lazy[node];
		lazy[node * 2 + 1] = lazy[node];
	}
	lazy[node] = 0;
}

void update(int node, int start, int end, int l, int r, ll val) {
	pushlazy(start, end, node);
	if (start > end or start > r or end < l)
		return;
	if (start >= l and end <= r) {
		if (tree[node].mx <= val) {
			lazy[node] = val;
			pushlazy(start, end, node);
			return;
		}
	}
	int mid = (start + end) / 2;
	if (tree[2 * node].mn <= val) update(node * 2, start, mid, l, r, val);
	if (tree[2 * node + 1].mn <= val) update(node * 2 + 1, mid + 1, end, l, r, val);
	tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
}

void query(int node, int start, int end, int l, int r, int &y, int &cnt) {
	if (start > end or start > r or end < l)
		return;
	pushlazy(start, end, node);
	if (l <= start and end <= r) {
		if (tree[node].sum <= y) {
			y -= tree[node].sum;
			cnt += end - start + 1;
			return;
		}
	}
	if (start != end) {
		int mid = (start + end) / 2;
		if (tree[2 * node].mn <= y) query(2 * node, start, mid, l, r, y, cnt);
		if (tree[2 * node + 1].mn <= y) query(2 * node + 1, mid + 1, end, l, r, y, cnt);
	}
}


void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	for (int i = 1; i <= q; i++) {
		int f, x, y;
		cin >> f >> x >> y;
		if (f == 1) {
			update(1, 1, n, 1, x, y);
		} else {
			int cnt = 0;
			query(1, 1, n, x, n, y, cnt);
			deb1(cnt)
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