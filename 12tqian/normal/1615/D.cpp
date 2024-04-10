#include <bits/stdc++.h>

using namespace std;

struct SCC {
	int n, ti;
	
	std::vector<std::vector<int>> g;
	
	std::vector<int> disc, comp, stk, comps;

	void init(int _n) {
		n = _n;
		ti = 0;
		g.resize(n);
		disc.resize(n);
		comp.assign(n, -1);
	}

	void ae(int u, int v) {
		g[u].push_back(v);
	}

	int dfs(int u) {
		int low = disc[u] = ++ti;
		stk.push_back(u);
		for (int v : g[u]) {
			if (comp[v] == -1) {
				low = std::min(low, disc[v] ? : dfs(v));
			}
		}
		if (low == disc[u]) {
			comps.push_back(u);
			for (int v  = -1; v != u; ) {
				comp[v = stk.back()] = u;
				stk.pop_back();
			}
		}
		return low;
	}

	void gen() {
		for (int i = 0; i < n; ++i) {
			if (disc[i] == 0) {
				dfs(i);
			}
		}
		reverse(comps.begin(), comps.end());
	}
};

struct TwoSat {
	int n = 0;
	
	std::vector<std::array<int, 2>> edges;

	void init(int n_) { n = n_; }
	
	int add_var() { return n++; }
	
	void either(int x, int y) {
		x = std::max(2 * x, -1 - 2 * x);
		y = std::max(2 * y, -1 - 2 * y);
		edges.push_back({x, y});
	}

	void implies(int x, int y) { either(~x, y); }
	
	void must(int x) { either(x, x); }
	
	void at_most_one(const std::vector<int>& v) {
		if ((int)v.size() <= 1) {
			return;
		}
		int cur = ~v[0];
		for (int i = 2; i < (int)v.size(); ++i) {
			int nxt = add_var();
			either(cur, ~v[i]);
			either(cur, nxt);
			either(~v[i], nxt);
			cur = ~nxt;
		}
		either(cur, ~v[1]);
	}
	
	std::vector<bool> solve(int n_ = -1) {
		if (n_ != -1) {
			n = n_;
		}
		SCC S;
		S.init(2 * n);
		for (auto [u, v] : edges) {
			S.ae(u ^ 1, v);
			S.ae(v ^ 1, u);
		}
		S.gen();
		reverse(S.comps.begin(), S.comps.end());
		for (int i = 0; i < 2 * n; i += 2) {
			if (S.comp[i] == S.comp[i ^ 1]) {
				return {};
			}
		}
		std::vector<int> tmp(2 * n);
		for (int i : S.comps) {
			if (tmp[i] == 0) {
				tmp[i] = 1;
				tmp[S.comp[i ^ 1]] = -1;
			}
		}
		std::vector<bool> ans(n);
		for (int i = 0; i < n; ++i) {
			ans[i] = tmp[S.comp[2 * i]] == 1;
		}
		return ans;
	}
};

void solve_case(int tc = 0) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	vector<vector<int>> ng(n);
	TwoSat ts;
	ts.init(n);
	auto cp = [&](int u, int v) {
		return array<int, 2>{min(u, v), max(u, v)};
	};
	map<array<int, 2>, int> val;
	auto ae = [&](int u, int v, int w) {
		if (w == 0) {
			ts.implies(u, v);
			ts.implies(v, u);
		} else if (w == 1) {
			ts.either(u, v);
			ts.at_most_one({u, v});
		}
	};
	for (int i = 0; i < n - 1; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		val[cp(u, v)] = w;
		if (w != -1) {
			w = __builtin_popcount(w) & 1;
		}
		ae(u, v, w);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		ae(u, v, w);
	}
	auto a = ts.solve();
	if (a.empty()) {
		cout << "NO" << '\n';
	} else {
		cout << "YES" << '\n';
		int cur = 0;
		function<void(int, int)> dfs = [&](int u, int p) {
			for (int v : g[u]) {
				if (v != p) {
					dfs(v, u);
				}
			}
			if (p != -1) {
				int w = a[u] ^ a[p];
				if (val[cp(u, p)] != -1) {
					w = val[cp(u, p)];
				}
				cout << u + 1 << ' ' << p + 1 << ' ' << w << '\n';
			}
		};
		dfs(0, -1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}