#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>

using namespace std;

struct DSU {
	vector<int> s, p;
	DSU(int n) : s(n, 1), p(n) { iota(p.begin(), p.end(), 0); }

	int get(int v) {
		return (v == p[v] ? v : p[v] = get(p[v]));
	}

	bool unite(int u, int v) {
		if ((u = get(u)) != (v = get(v))) {
			if (s[u] < s[v]) {
				swap(u, v);
			}
			s[u] += s[v];
			p[v] = u;
			return true;
		}
		return false;
	}
};

struct Edge {
	int u, v, w, i;
	
	bool operator < (const Edge& e) const {
		return w < e.w;
	}
};

void dfs(int v, DSU& dsu, const set<pair<int, int>>& ban, set<int>& unvis) {
	vector<int> nb;
	for (int to : unvis) {
		if (!ban.count({ v, to })) {
			nb.push_back(to);
		}
	}
	for (int to : nb) {
		unvis.erase(to);
		dsu.unite(v, to);
	}
	for (int to : nb) {
		dfs(to, dsu, ban, unvis);
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<Edge> es(m);
	int xr = 0;
	set<pair<int, int>> ban;
	for (auto& e : es) {
		cin >> e.u >> e.v >> e.w;
		--e.u;
		--e.v;
		xr ^= e.w;
		ban.insert({ e.u, e.v });
		ban.insert({ e.v, e.u });
	}
	set<int> unvis;
	for (int u = 0; u < n; u++) {
		unvis.insert(u);
	}
	DSU dsu(n);
	for (int u = 0; u < n; u++) {
		if (unvis.count(u)) {
			unvis.erase(u);
			dfs(u, dsu, ban, unvis);
		}
	}
	sort(es.begin(), es.end());
	int cw = 0;
	long long w = 0;
	for (auto e : es) {
		if (dsu.unite(e.u, e.v)) {
			cw++;
			w += e.w;
		}
	}
	if (1LL * n * (n - 1) / 2 - m > n - 1 - cw) {
		cout << w << endl;
	}
	else {
		int tmp = 0;
		for (int u = 0; u < n; u++) {
			for (int v = u + 1; v < n; v++) {
				if (!ban.count({ u, v })) {
					es.push_back({ u, v, 0, --tmp });
				}
			}
		}
		long long ans = w + xr;
		for (int i = -1; i >= tmp; i--) {
			for (auto& e : es) {
				if (e.i < 0) {
					e.w = 0;
				}
				if (e.i == i) {
					e.w = xr;
				}
			}
			sort(es.begin(), es.end());
			DSU dsu(n);
			long long cur = 0;
			for (const auto& e : es) {
				if (dsu.unite(e.u, e.v)) {
					cur += e.w;
				}
			}
			ans = min(ans, cur);
		}
		cout << ans << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	solve();
}