#include "bits/stdc++.h"
using namespace std;


int main() {
	int n; int m; int k; int s;
	while (~scanf("%d%d%d%d", &n, &m, &k, &s)) {
		vector<int> a(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &a[i]), -- a[i];
		vector<vector<int> > g(n);
		for (int i = 0; i < m; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		const int INF = 0x3f3f3f3f;
		vector<vector<int>> costs(n, vector<int>(k));
		vector<int> que, dist;
		for (int kk = 0; kk < k; ++ kk) {
			que.assign(n, -1);
			dist.assign(n, INF);
			int qt = 0;
			for (int i = 0; i < n; ++ i) if (a[i] == kk) {
				dist[i] = 0;
				que[qt ++] = i;
			}
			for (int qh = 0; qh < qt; ++ qh) {
				int i = que[qh];
				for (int j : g[i]) if (dist[j] == INF) {
					dist[j] = dist[i] + 1;
					que[qt ++] = j;
				}
			}
			for (int i = 0; i < n; ++ i)
				costs[i][kk] = dist[i];
		}
		vector<int> ans(n, 0);
		for (int i = 0; i < n; ++ i) {
			auto &v = costs[i];
			nth_element(v.begin(), v.begin() + s, v.end());
			for (int j = 0; j < s; ++ j)
				ans[i] += v[j];
		}
		for (int i = 0; i < (int)ans.size(); ++ i) {
			if (i != 0) putchar(' ');
			printf("%d", ans[i]);
		}
		puts("");
	}
}