#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;
	while (~scanf("%d", &n)) {
		vector<vector<int> > g(n);
		for (int i = 0; i < n - 1; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		vector<int> queue(n, -1);
		vector<bool> vis(n);
		vector<pair<int, int>> ans;
		for (int s = 0; s < n; ++ s) if (!vis[s] && (int)g[s].size() <= 1) {
			vis[s] = true;
			int qt = 0;
			queue[qt ++] = s;
			bool end = false;
			for (int qh = 0; qh < qt; ++ qh) {
				int i = queue[qh];
				for (int j : g[i]) if (!vis[j]) {
					if ((int)g[j].size() <= 2) {
						vis[j] = true;
						queue[qt ++] = j;
					} else {
						ans.emplace_back(j, s);
						end = true;
						break;
					}
				}
			}
			if (!end)
				ans.emplace_back(queue[qt - 1], s);
		}
		bool ok = count(vis.begin(), vis.end(), true) >= n - 1;
		if (count(vis.begin(), vis.end(), true) == n - 1) {
			for (auto p : ans)
				ok &= !vis[p.first];
		}
		puts(ok ? "Yes" : "No");
		if (ok) {
			printf("%d\n", (int)ans.size());
			for (int i = 0; i < (int)ans.size(); ++ i)
				printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
		}
	}
}