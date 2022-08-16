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

const ll   N     =  2e3 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, k, a[N];

struct NODE {
	vector <ll> ans;
	NODE () {
		ans.assign(k + 1, INFi);
	}
};

NODE tree[4 * N + 8];

NODE combine(NODE a, NODE b) {
	NODE c;
	for (int i = 0; i <= k; i++) {
		c.ans[i] = min(a.ans[i], b.ans[i]);
	}
	return c;
}

void build(int node, int start, int end) {
	if (start == end) {
		tree[node] = NODE();
		if (start == 0) tree[node].ans[0] = 0;
	}
	else {
		int mid = (start + end) / 2;
		build(2 * node, start, mid);
		build(2 * node + 1, mid + 1, end);
		tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
	}
}

void update(int node, int start, int end, int idx, vector <ll> a) {
	if (start == end) {
		for (int i = 0; i <= k; i++) {
			tree[node].ans[i] = min(tree[node].ans[i], a[i]);
		}
		// debv(tree[node].ans)
	}
	else {
		int mid = (start + end) / 2;
		if (start <= idx and idx <= mid)
			update(2 * node, start, mid, idx, a);
		else
			update(2 * node + 1, mid + 1, end, idx, a);
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

void solve() {
	cin >> n >> k;
	vector <vector<ll>> dp(n + 1, vector <ll>(k + 1, INFi));
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 0, n);
	int ans = INFi;
	for (int i = 1; i <= n; i++) {
		int x = i - a[i];
		if (x < 0) continue;
		auto it = query(1, 0, n, 0, a[i] - 1);
		for (int j = 1; j <= k; j++) {
			dp[i][j] = it.ans[j - 1] <= x? x : INFi;
		}
		if (dp[i][k] <= n) {
			ans = min(ans, x);
		}
		update(1, 0, n, a[i], dp[i]);
	}
	if (ans > n) ans = -1;
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