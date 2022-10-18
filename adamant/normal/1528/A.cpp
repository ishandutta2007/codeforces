#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int mod = 1e9 + 7;
const int maxn = 1e5 + 42;

int add(int a, int b) {
	return (a + b) % mod;
}
int mul(int a, int b) {
	return a * b % mod;
}
int bpow(int x, int n) {
	return n ? n % 2 ? mul(x, bpow(x, n - 1)) : bpow(mul(x, x), n / 2)  : 1;
}
int inv(int x) {
	return bpow(x, mod - 2);
}

pair<int, int> dfs(vector<int> *g, int *l, int *r, int v = 0, int p = 0) {
	pair<int, int> ans = {0, 0};
	for(auto u: g[v]) {
		if(u != p) {
			auto res = dfs(g, l, r, u, v);
			ans.first += max(res.first + abs(l[v] - l[u]), res.second + abs(l[v] - r[u]));
			ans.second += max(res.first + abs(r[v] - l[u]), res.second + abs(r[v] - r[u]));
		}
	}
	return ans;
}

void solve() {
	int n;
	cin >> n;
	int l[n], r[n];
	for(int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
	}
	vector<int> g[n];
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	auto ans = dfs(g, l, r);
	cout << max(ans.first, ans.second) << endl;
}

signed main() {
	//ignore = freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}