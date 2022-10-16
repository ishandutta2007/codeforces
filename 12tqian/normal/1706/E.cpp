#include <bits/stdc++.h>

using namespace std;

template <class T> struct SparseTable {
	std::vector<T> v;
	std::vector<std::vector<int>> jump;

	int level(int x) { return 31 - __builtin_clz(x); }

	int comb(int a, int b) {
		return v[a] == v[b] ? std::min(a, b) : (v[a] > v[b] ? a : b);
	}

	void init(const std::vector<T>& _v) {
		v = _v;
		jump = {std::vector<int>((int)v.size())};
		iota(jump[0].begin(), jump[0].end(), 0);
		for (int j = 1; (1 << j) <= (int)v.size(); j++) {
			jump.push_back(std::vector<int>((int)v.size() - (1 << j) + 1));
			for (int i = 0; i < (int)jump[j].size(); i++) {
				jump[j][i] = comb(jump[j - 1][i], jump[j - 1][i + (1 << (j - 1))]);
			}
		}
	}

	int index(int l, int r) {
		assert(l <= r);
		int d = level(r - l + 1);
		return comb(jump[d][l], jump[d][r - (1 << d) + 1]);
	}

	T query(int l, int r) {
		return v[index(l, r)];
	}
};

void solve_case(int tc = 0) {
	int n, m, q;
	cin >> n >> m >> q;
	vector<array<int, 2>> edges(m);
	for (auto& e : edges) {
		for (auto& u : e) {
			cin >> u;
			--u;
		}
	}
	vector<set<int>> use(n);
	vector<int> par(n);
	for (int i = 0; i < n; ++i) {
		par[i] = -1;
		use[i].insert(i);
	}
	auto get = [&](int x) {
		while (par[x] != -1) {
			x = par[x];
		}
		return x;
	};
	vector<int> conn(n - 1, m);
	for (int i = 0; i < m; ++i) {
		int u = edges[i][0];
		int v = edges[i][1];
		u = get(u);
		v = get(v);
		if (u != v) {
			if (use[u].size() < use[v].size()) {
				swap(u, v);
			}
			for (int z : use[v]) {
				if (use[u].count(z - 1)) {
					conn[z - 1] = min(conn[z - 1], i);
				}
				if (use[u].count(z + 1)) {
					conn[z] = min(conn[z], i);
				}
				use[u].insert(z);
			}
			par[v] = u;
		}
	}
	SparseTable<int> st;
	st.init(conn);
	while (q--) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		int ans;
		if (l == r) {
			ans = 0;
		} else {
			ans = st.query(l, r - 1) + 1;
		}
		cout << ans << ' ';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1;
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}