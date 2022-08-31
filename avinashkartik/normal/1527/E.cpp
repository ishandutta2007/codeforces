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

const ll   N     =  4e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, k, a[N], dp[N], lazy[4 * N + 8];

struct NODE {
	ll dp, min;
	NODE(): dp(0), min(0) {}
};

NODE tree[4 * N + 8];

NODE combine(NODE a, NODE b) {
	if (a.dp - a.min < b.dp - b.min) return a;
	return b;
}

void build(int node, int start, int end) {
	if (start == end) {
		tree[node].dp = dp[start - 1];
		tree[node].min = 0;
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
	tree[node].min += lazy[node];
	if (start != end) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}

void update(int node, int start, int end, int l, int r, ll val) {
	pushlazy(start, end, node);
	if (start > end or start > r or end < l)
		return;
	if (start >= l and end <= r) {
		lazy[node] += val;
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
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	map <int, int> f, l;
	ll fsum = 0, lsum = 0;
	for (int i = 1; i <= n; i++) {
		if (f.find(a[i]) == f.end()) f[a[i]] = i, fsum += i;
		lsum -= l[a[i]];
		l[a[i]] = i;
		lsum += l[a[i]];
		dp[i] = lsum - fsum;
	}
	for (int itr = 1; itr < k; itr++) {
		mset(lazy, 0);
		build(1, 1, n);
		l.clear();
		lsum = 0;
		for (int i = 1; i <= n; i++) {
			update(1, 1, n, l[a[i]] + 1, n, i - l[a[i]]);
			lsum -= l[a[i]];
			l[a[i]] = i;
			lsum += l[a[i]];
			NODE x = query(1, 1, n, 1, i);
			if (i != 1) dp[i] = min(dp[i], x.dp + lsum - x.min);
		}
	}
	deb1(dp[n])
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}