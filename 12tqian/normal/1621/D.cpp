#include <bits/stdc++.h>

using namespace std;

template <class C, bool directed> struct Dijkstra {
	int SZ; std::vector<C> dist;
	std::vector<std::vector<std::pair<int, C>>> adj;

	void init(int _SZ) {
		SZ = _SZ;
		adj.clear();
		adj.resize(SZ);
	}

	void ae(int u, int v, C cost) {
		adj[u].emplace_back(v, cost);
		if (!directed) adj[v].emplace_back(u, cost);
	}

	void gen(int st) {
		dist = std::vector<C>(SZ, std::numeric_limits<C>::max());
		typedef std::pair<C, int> T;
		std::priority_queue<T, std::vector<T>, std::greater<T>> pq;
		auto ad = [&](int a, C b) {
			if (dist[a] <= b) return;
			pq.push({dist[a] = b, a});
		};
		ad(st, 0);
		while (!pq.empty()) {
			auto x = pq.top();
			pq.pop();
			if (dist[x.second] < x.first) continue;
			for (auto& y: adj[x.second]) {
				ad(y.first, x.first + y.second);
			}
		}
	}
};

void solve_case(int tc = 0) { 
	const long long INF = 1e18;
	int n;
	cin >> n;
	vector<vector<int>> c(2 * n, vector<int>(2 * n));
	for (int i = 0; i < 2 * n; ++i) {
		for (int j = 0; j < 2 * n; ++j) {
			cin >> c[i][j];
		}
	}
	long long ans = 0;
	for (int i = n; i < 2 * n; ++i) {
		for (int j = n; j < 2 * n; ++j) {
			ans += c[i][j];
			c[i][j] = 0;
		}
	}
	ans += min({c[2 * n - 1][0], c[0][2 * n - 1], c[2 * n - 1][n - 1], c[n - 1][2 * n - 1], c[0][n], c[n][0], c[n - 1][n], c[n][n - 1]});
	cout << ans << '\n';
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