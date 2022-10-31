#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;
	while (~scanf("%d", &n)) {
		vector<int> S(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &S[i]);
		int m;
		scanf("%d", &m);
		vector<vector<int> > g(n);
		vector<pair<int, int>> edges(m * 2);
		for (int i = 0; i < m; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			for (int k = 0; k < 2; ++ k) {
				edges[i * 2 + k] = { u, v };
				g[u].push_back(i * 2 + k);
				swap(u, v);
			}
		}
		bool ok = true;
		vector<int> flow(m * 2, 0);
		vector<int> queue(n, -1);
		vector<bool> vis(n);
		vector<int> sums = S;
		vector<int> treeEdge(n, -1);
		for (int si = 0; si < n; ++ si) if (!vis[si]) {
			int qt = 0;
			vis[si] = true;
			queue[qt ++] = si;
			for (int qh = 0; qh < qt; ++ qh) {
				int i = queue[qh];
				for (int ei : g[i]) {
					int j = edges[ei].second;
					if (!vis[j]) {
						vis[j] = true;
						treeEdge[j] = ei;
						queue[qt ++] = j;
					}
				}
			}
			for (int qi = qt - 1; qi > 0; -- qi) {
				int i = queue[qi], ei = treeEdge[i], p = edges[ei].first;
				flow[ei] += sums[i];
				sums[p] += sums[i];
			}
			if (sums[si] != 0) {
				ok = false;
				break;
			}
		}
		puts(ok ? "Possible" : "Impossible");
		if (ok) {
			vector<int> ans(m);
			for (int i = 0; i < m; ++ i)
				ans[i] = flow[i * 2 + 0] - flow[i * 2 + 1];
			for (int i = 0; i < (int)ans.size(); ++ i)
				printf("%d\n", ans[i]);
		}
	}
}