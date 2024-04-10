#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;
	int K = 2;
	vector<vector<int>> g(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<vector<long long>> dist(n, vector<long long>(K));
	vector<vector<long long>> cnt(n, vector<long long>(K));
	function<void(int, int)> dfs = [&](int u, int p) {
		cnt[u][0] = 1;
		for (int v : g[u]) {
			if (v == p) {
				continue;
			}
			dfs(v, u);
			for (int i = 0; i < K; i++) {
				dist[u][(i + 1) % K] += dist[v][i] + cnt[v][i];
				cnt[u][(i + 1) % K] += cnt[v][i];
			}
		}
	};
	dfs(0, -1);
	long long ans = 0;
	function<void(int, int)> dfs2 = [&](int u, int p) {
		vector<long long> dist0(K);
		vector<long long> cnt0(K);
		cnt0[0]++;
		for (int v : g[u]) {
			for (int i = 0; i < K; i++) {
				dist0[(i + 1) % K] += dist[v][i] + cnt[v][i];
				cnt0[(i + 1) % K] += cnt[v][i];
			}
		}
		for (int i = 0; i < K; i++) {
			if (i == 0) {
				ans += dist0[i] / K;
			}
			else {
				ans += (dist0[i] - cnt0[i] * i) / K;
				ans += cnt0[i];
			}
		}
		auto tmp0 = dist[u];
		auto tmp1 = cnt[u];
		dist[u] = dist0;
		cnt[u] = cnt0;
		for (int v : g[u]) {
			if (v == p) {
				continue;
			}
			for (int i = 0; i < K; i++) {
				dist[u][(i + 1) % K] -= dist[v][i] + cnt[v][i];
				cnt[u][(i + 1) % K] -= cnt[v][i];
			}
			dfs2(v, u);
			for (int i = 0; i < K; i++) {
				dist[u][(i + 1) % K] += dist[v][i] + cnt[v][i];
				cnt[u][(i + 1) % K] += cnt[v][i];
			}
		}
		dist[u] = tmp0;
		cnt[u] = tmp1;
	};
	dfs2(0, -1);
	cout << ans / 2 << endl;
}