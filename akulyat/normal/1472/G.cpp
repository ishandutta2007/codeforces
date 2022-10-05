#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m;
vector<vector<int>> e, re;
vector<int> d;
bool viv = false;

void BFS() {
	d.assign(n, mod);
	deque<int> st(1, 0);
	d[0] = 0;
	while (st.size()) {
		int v = st[0];
		st.pop_front();
		for (auto u : e[v])
			if (d[u] > d[v] + 1) {
				d[u] = d[v] + 1;
				st.push_back(u);
			}
	}
	if (viv) {
		for (auto i : d)
			cout << i << ' ';
		cout << '\n';
	}
}

void solve() {
	cin >> n >> m;
	e.assign(n, {});
	re.assign(n, {});
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		e[u].push_back(v);
		re[v].push_back(u);
	}
	BFS();

	vector<int> ord(n);
	for (int i = 0; i < n; i++)
		ord[i] = i;
	sort(ord.begin(), ord.end(), [&](int i, int j) {
			return (d[i] > d[j]);
		} 
	);
	if (viv) {
		cout << "ord: ";
		for (auto i : ord)
			cout << i << ' ';
		cout << endl;
	}
	auto dp = d;
	for (auto v : ord) {
		for (auto u : e[v]) {
			if (d[u] <= d[v])
				dp[v] = min(dp[v], d[u]);
			else
				dp[v] = min(dp[v], dp[u]);
		}
	}
	if (viv)
		cout << "\tANS: ";
	for (auto i : dp)
		cout << i << ' ';
	cout << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}