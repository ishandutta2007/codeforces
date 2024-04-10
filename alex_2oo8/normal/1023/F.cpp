#include <bits/stdc++.h>

using namespace std;

const int MX = 500000;
const long long INF = 1e16;

namespace dsu {
	int p[MX];
	
	void init(int n) {
		iota(p, p + n, 0);
	}
	
	int get(int v) {
		if (p[v] != v) p[v] = get(p[v]);
		return p[v];
	}
	
	bool merge(int u, int v) {
		u = get(u);
		v = get(v);
		p[u] = v;
		return u != v;
	}
}

vector<pair<int, bool>> G[MX];
set<int> S[MX];
int w[MX];

long long dfs(int v, int p = -1, bool add = false) {
	long long res = 0;
	for (auto& e : G[v]) {
		if (e.first == p) continue;
		
		res += dfs(e.first, v, e.second);
		if (res >= INF) res = INF;
		
		if (S[e.first].size() > S[v].size()) swap(S[e.first], S[v]);
		for (int x : S[e.first]) {
			// TODO: improve
			if (S[v].count(x) == 1) S[v].erase(x);
			else S[v].insert(x);
		}
	}
	
	if (add) {
		if (S[v].empty()) res = INF;
		else res += w[*S[v].begin()];
	}
	
	return min(res, INF);
}

int main() {
	int n, k, m;
	ignore = scanf("%d %d %d", &n, &k, &m);
	dsu::init(n);
	for (int i = 0, u, v; i < k; i++) {
		ignore = scanf("%d %d", &u, &v);
		u--, v--;
		G[u].emplace_back(v, true);
		G[v].emplace_back(u, true);
		dsu::merge(u, v);
	}
	
	for (int i = 0, u, v; i < m; i++) {
		ignore = scanf("%d %d %d", &u, &v, w + i);
		u--, v--;
		if (dsu::merge(u, v)) {
			G[u].emplace_back(v, false);
			G[v].emplace_back(u, false);
		}
		else {
			S[u].insert(i);
			S[v].insert(i);
		}
	}
	
	long long ans = dfs(0);
	
	if (ans == INF) ans = -1;
	printf("%lld\n", ans);
	
	return 0;
}