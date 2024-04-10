#include <bits/stdc++.h>
using namespace std;
int n, a[500005], b[500005];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d", &a[i], &b[i]);
	for (int k = 20; k >= 0; k--) {
		vector<vector<pair<int, int> > > G((1 << k) + n);
		for (int i = 0; i < n; i++) {
			G[a[i] & ((1 << k) - 1)].emplace_back((1 << k) + i, 2 * i + 1);
			G[(1 << k) + i].emplace_back(a[i] & ((1 << k) - 1), 2 * i + 1);
			G[b[i] & ((1 << k) - 1)].emplace_back((1 << k) + i, 2 * i + 2);
			G[(1 << k) + i].emplace_back(b[i] & ((1 << k) - 1), 2 * i + 2);
		}
		int bad = 0;
		for (int i = 0; i < (1 << k) + n; i++) {
			if (G[i].size() % 2 == 1) {
				bad = 1;
				break;
			}
		}
		if (bad) continue;
		vector<bool> vis(2 * n + 1, false);
		vector<int> ans;
		function<void(int, int)> dfs = [&](int u, int lst) {
			while (!G[u].empty()) {
				int v = G[u].back().first, fr = G[u].back().second;
				G[u].pop_back();
				if (vis[fr]) continue;
				vis[fr] = true;
				dfs(v, fr);
			}
			if (lst) ans.push_back(lst);
		};
		for (int i = 0; i < (1 << k) + n; i++) {
			if (G[i].size()) {
				dfs(i, 0);
				break;
			}
		}
		if ((int)ans.size() < 2 * n) continue;
		printf("%d\n", k);
		for (int x : ans) printf("%d ", x);
		return 0;
	}
	return 0;
}