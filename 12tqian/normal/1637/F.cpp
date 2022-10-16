#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	long long INF = 1e18;
	int n;
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}
	vector<vector<int>> g(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int mx = *max_element(h.begin(), h.end());
	vector<int> t(n);
	long long cur = 0;
	vector<multiset<int>> store(n);
	function<void(int, int)> dfs = [&](int u, int p) {
		for (int v : g[u]) {
			if (v != p) {
				dfs(v, u);	
				t[u] = max(t[u], t[v]);
				store[u].insert(t[v]);
			}
		}
		if (u == 0) {
			cur += mx;
		} 
		cur += max(h[u] - t[u], 0);
		t[u] = max(t[u], h[u]);
	};
	dfs(0, -1);
	auto value = [&](int root, int u) {
		long long ret = 0;
		if (u == root) {
			ret += mx;
		}
		if (store[u].empty()) {
			ret += h[u];
		} else {
			ret += max(h[u] - *store[u].rbegin(), 0);
		}
		return ret;
	};
	auto get_efficieny = [&](int u) {
		if (store[u].empty()) {
			return h[u];
		} else {
			return max(*store[u].rbegin(), h[u]);
		}
	};
	auto move = [&](int u, int v) { // root moves from u to v
		cur -= value(u, u);
		cur -= value(u, v);
		store[u].erase(store[u].find(t[v]));
		t[u] = get_efficieny(u);
		store[v].insert(t[u]);
		t[v] = get_efficieny(v);
		cur += value(v, u);
		cur += value(v, v);
	};
	long long ans = INF;
	function<void(int, int)> reroot = [&](int u, int p) {
		ans = min(ans, cur);
		for (int v : g[u]) {
			if (v != p) {
				move(u, v);
				reroot(v, u);
				move(v, u);
			}
		}
	};
	reroot(0, -1);
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1;
	// cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}