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

ll n, m, l[N], r[N], dp[N], wh[N];
vector <int> w[N];

struct NODE {
	int ans;
	NODE(): ans(0) {}
};

NODE tree[4 * N + 8];
int lazy[4 * N + 8];

NODE combine(NODE a, NODE b) {
	if (dp[a.ans] > dp[b.ans]) return a;
	return b;
}

void pushlazy(int start, int end, int node) {
	if (lazy[node] == 0) return;
	tree[node].ans = max(tree[node].ans, lazy[node]);
	if (start != end) {
		if (dp[lazy[node]] > dp[lazy[node * 2]]) lazy[node * 2] = lazy[node];
		if (dp[lazy[node]] > dp[lazy[node * 2 + 1]]) lazy[node * 2 + 1] = lazy[node];
	}
	lazy[node] = 0;
}

void update(int node, int start, int end, int l, int r, int v) {
	pushlazy(start, end, node);
	if (start > end or start > r or end < l)
		return;
	if (start >= l and end <= r) {
		if (dp[lazy[node]] < dp[v]) lazy[node] = v;
		pushlazy(start, end, node);
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, l, r, v);
	update(node * 2 + 1, mid + 1, end, l, r, v);
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


void solve() {
	cin >> n >> m;
	vector <int> p;
	for (int i = 1; i <= m; i++) {
		int x; cin >> x >> l[i] >> r[i];
		w[x].pb(i);
		p.pb(l[i]);
		p.pb(r[i]);
	}
	sort(all(p));
	uniq(p);
	for (int i = 1; i <= m; i++) {
		l[i] = lower_bound(all(p), l[i]) - p.begin();
		r[i] = lower_bound(all(p), r[i]) - p.begin();
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		wh[i] = 0;
		for (auto it : w[i]) {
			NODE q = query(1, 0, 2 * m, l[it], r[it]);
			if (dp[q.ans] + 1 > dp[i]) {
				wh[i] = q.ans;
			}
			dp[i] = max(dp[i], dp[q.ans] + 1);
		}
		for (auto it : w[i]) {
			update(1, 0, 2 * m, l[it], r[it], i);
		}
	}
	set <int> s;
	for (int i = 1; i <= n; i++) s.insert(i);
	int mx = max_element(dp + 1, dp + n + 1) - dp;
	while (mx) {
		s.erase(mx);
		mx = wh[mx];
	}
	deb1(s.size());
	debv(s)
}

int main() {
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}