#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e6 + 5;

#define pii pair<int, int>

int n, m;
int us[N], vs[N];
vector<pii> G[N];
vector<int> tour;
boolean vis[N << 1], reserve[N];

void dfs(int p) {
	while (!G[p].empty()) {
		pii par = G[p].back();
		G[p].pop_back();
		if (vis[par.second])
			continue;
		vis[par.second] = true;
		dfs(par.first);
		tour.push_back(par.second);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v; i <= m; i++) {
		scanf("%d%d", &u, &v);
		us[i] = u, vs[i] = v;
		G[u].emplace_back(v, i);
		G[v].emplace_back(u, i);
	}
	int K = m;
	for (int i = 1; i <= n; i++) {
		if (G[i].size() & 1) {
			G[0].emplace_back(i, ++K);
			G[i].emplace_back(0, K);
		}
	}
	for (int i = 0; i <= n; i++) {
		tour.clear();
		dfs(i);
		if (tour.size()) {
			int S = tour.size();
			for (int i = 0; i < S; i += 2) {
				if (tour[i] > m) {
					int pre = tour[(i - 1 + S) % S];
					int suf = tour[(i + 1) % S];
					assert(pre <= m || suf <= m);
					if (pre <= m) {
						reserve[pre] = true;
					} else {
						reserve[suf] = true;
					}
				} else {
					reserve[tour[i]] = true;
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= m; i++)
		cnt += reserve[i];
	printf("%d\n", cnt);
	for (int i = 1; i <= m; i++) {
		if (reserve[i]) {
			printf("%d %d\n", us[i], vs[i]);
		}
	}
	return 0;
}