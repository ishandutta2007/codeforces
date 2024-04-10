#include <bits/stdc++.h>

using namespace std;

struct DSU {
	vector<int> e;
	int comps;

	void init(int n) {
		e = vector<int>(n, -1);
		comps = n;
	}

	int get(int x) {
		return e[x] < 0 ? x : e[x] = get(e[x]);
	}

	bool same_set(int a, int b) {
		return get(a) == get(b);
	}

	int size(int x) {
		return -e[get(x)];
	}

	bool unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		--comps;
		return true;
	}
};

void solve_case(int tc = 0) {
	int n, m1, m2;
	cin >> n >> m1 >> m2;
	DSU d1, d2;
	d1.init(n), d2.init(n);
	for (int i = 0; i < m1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		d1.unite(u, v);
	}
	for (int i = 0; i < m2; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		d2.unite(u, v);
	}
	vector<array<int, 2>> edges;
	if (d1.comps > d2.comps) {
		swap(d1, d2);
		swap(m1, m2);
	}
	map<int, vector<int>> c1;
	map<int, vector<int>> c2;
	for (int i = 0; i < n; ++i) {
		c1[d1.get(i)].push_back(i);
		c2[d2.get(i)].push_back(i);
	}
	cout << (int)min(c1.size(), c2.size()) - 1 << '\n';
	while ((int)c1.size() >= 2 && (int)c2.size() >= 2) {
		int x = c1.begin()->second[0];
		int y = next(c1.begin())->second[0];
		int p = c2.begin()->second[0];
		int q = next(c2.begin())->second[0];
		auto merge = [&](int x, int y) {
			if (d1.same_set(x, y) || d2.same_set(x, y)) {
				return false;
			} else {
				{
					int ox = d1.get(x);
					int oy = d1.get(y);
					d1.unite(x, y);
					if (ox != d1.get(x)) {
						swap(ox, oy);
					}
					if (c1[ox].size() < c1[oy].size()) {
						swap(ox, oy);
					}
					for (int z : c1[oy]) {
						c1[ox].push_back(z);
					}
					c1.erase(oy);
				}
				{
					int ox = d2.get(x);
					int oy = d2.get(y);
					d2.unite(x, y);
					if (ox != d2.get(x)) {
						swap(ox, oy);
					}
					if (c2[ox].size() < c2[oy].size()) {
						swap(ox, oy);
					}
					for (int z : c2[oy]) {
						c2[ox].push_back(z);
					}
					c2.erase(oy);
				}
				cout << x + 1 << ' ' << y + 1 << '\n';
				return true;
			}
		};
		if (merge(x, y)) {
		} else if (merge(x, p)) {
		} else if (merge(x, q)) {
		} else if (merge(y, p)) {
		} else if (merge(y, q)) {
		} else {
			assert(false);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1;
	for (int tc = 1; tc <= tt; ++ tc) {
		solve_case(tc);
	}
	return 0;
}