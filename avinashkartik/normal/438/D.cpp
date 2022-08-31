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

const ll   N     =  1e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

int n, q, a[N];

struct NODE {
	ll sum, mx;
	NODE(): sum(0), mx(-INFi) {}
	NODE(int x): sum(x), mx(x) {}
};

NODE tree[4 * N + 8];

NODE combine(NODE a, NODE b) {
	NODE c;
	c.sum = a.sum + b.sum;
	c.mx = max(a.mx, b.mx);
	return c;
}

void build(int node, int start, int end) {
	if (start == end) {
		tree[node] = NODE(a[start]);
	} else {
		int mid = (start + end) / 2;
		build(2 * node, start, mid);
		build(2 * node + 1, mid + 1, end);
		tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
	}
}

void update(int node, int start, int end, int idx, int val) {
	if (start == end) {
		tree[node] = NODE(val);
	} else {
		int mid = (start + end) / 2;
		if (start <= idx and idx <= mid)
			update(2 * node, start, mid, idx, val);
		else
			update(2 * node + 1, mid + 1, end, idx, val);
		tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
	}
}

NODE query(int node, int start, int end, int l, int r) {
	if (start > end or start > r or end < l)
		return NODE();
	if (l <= start and end <= r)
		return tree[node];
	int mid = (start + end) / 2;
	NODE p1 = query(2 * node, start, mid, l, r);
	NODE p2 = query(2 * node + 1, mid + 1, end, l, r);
	return combine(p1, p2);
}

int findmin(int node, int start, int end, int l, int mod) {
	if (start > end or end < l)
		return n + 1;
	if (start == end)
		return a[start] >= mod? start : n + 1;
	int mid = (start + end) / 2;
	if (tree[2 * node].mx >= mod) {
		int p1 = findmin(2 * node, start, mid, l, mod);
		if (a[p1] >= mod) return p1;
		return findmin(2 * node + 1, mid + 1, end, l, mod);
	}
	return findmin(2 * node + 1, mid + 1, end, l, mod);
}

void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	while (q--) {
		int type, l, r, x;
		cin >> type;
		if (type == 1) {
			cin >> l >> r;
			deb1(query(1, 1, n, l, r).sum)
		} else if (type == 2) {
			cin >> l >> r >> x;
			while (l <= r) {
				if (a[l] >= x) {
					a[l] %= x;
					update(1, 1, n, l, a[l]);
				}
				l = findmin(1, 1, n, l, x);
			}
		} else {
			cin >> l >> x;
			a[l] = x;
			update(1, 1, n, l, a[l]);
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