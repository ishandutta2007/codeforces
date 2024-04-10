#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef int       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7 + 100 * kk;
const long long inf = mod; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, m;
vector<vector<pii>> e;
vector<vector<ll>> ans;
bool viv = false;

void read() {
	cin >> n >> m;
	e.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		e[a].push_back({b, c});
	}
}

void work(int v) {
	vector<ll> lans(n, inf);
	vector<bool> used(n, false);
	lans[v] = 0;
	for (int i = 0; i < n; i++) {
		ll bst = 2 * inf, u = -1;
		for (int j = 0; j < n; j++)
			if (!used[j] && lans[j] < bst)
				bst = lans[j], u = j;
		used[u] = true;
		vector<ll> llans(n, inf);
		for (auto p : e[u]) {
			int t = p.F;
			t += lans[u];
			t %= n;
			int w = p.S;
			llans[t] = min(llans[t], lans[u] + w);
		}
		for (int i = 0; i < n; i++) 
			llans[(i + 1) % n] = min(llans[(i + 1) % n], llans[i] + 1);
		for (int i = 0; i < n; i++) 
			llans[(i + 1) % n] = min(llans[(i + 1) % n], llans[i] + 1);
		for (int i = 0; i < n; i++) 
			lans[i] = min(lans[i], llans[i]);
	}
	ans[v] = lans;
	// cout << v << ": ";
	// for (auto i : lans)
	// 	cout << i << ' ';
	// cout << endl;
}

void work() {
	ans.resize(n);
	for (int i = 0; i < n; i++) {
		work(i);
	}
}

void solve() {
	read();
	work();
	for (auto lans : ans) {
		for (auto val : lans)
			cout << val << ' ';
		cout << '\n';
	}
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}