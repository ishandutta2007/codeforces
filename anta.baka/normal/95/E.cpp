#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <random>

using namespace std;

int n, m;
vector<vector<int>> g;
vector<bool> was;
int sz;

void dfs(int v) {
	was[v] = true;
	sz++;
	for (int to : g[v]) {
		if (!was[to]) {
			dfs(to);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	was.resize(n);
	map<int, int> mapik;
	for (int u = 0; u < n; u++) {
		if (!was[u]) {
			sz = 0;
			dfs(u);
			mapik[sz]++;
		}
	}
	vector<pair<int, int>> obs;
	for (auto p : mapik) {
		obs.emplace_back(p);
	}
	shuffle(obs.begin(), obs.end(), mt19937(228));
	n++;
	const int inf = 1e9 + 228;
	vector<int> dp(n, inf);
	dp[0] = -1;
	for (auto ob : obs) {
		for (int r = 0; r < ob.first; r++) {
			deque<pair<int, int>> q;
			int add = 0;
			for (int i = r, j = 0; i < n; i += ob.first, j++) {
				int old = dp[i];
				dp[i] = min(dp[i], (q.empty() ? inf : q[0].first + add));
				while (!q.empty() && q.back().first + add >= old) {
					q.pop_back();
				}
				q.push_back({ old - add, j });
				if (j >= ob.second) {
					if (q[0].second == (j - ob.second)) {
						q.pop_front();
					}
				}
				add++;
			}
		}
	}
	int ans = inf;
	for (int x = 1; x < n; x++) {
		auto kek = [](int v) {
			while (v) {
				if (v % 10 != 4 && v % 10 != 7) {
					return false;
				}
				v /= 10;
			}
			return true;
		};
		if (kek(x)) {
			ans = min(ans, dp[x]);
		}
	}
	cout << (ans == inf ? -1 : ans) << endl;
}