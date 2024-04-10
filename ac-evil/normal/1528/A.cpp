#include <bits/stdc++.h>
typedef long long LL;
const int N = 200005;
int T, n, l[N], r[N];
std::vector<int> G[N];
LL dp[N][2];
void dfs(int u, int f) {
	for (int v : G[u])
		if (v != f) dfs(v, u);
	for (int v : G[u]) {
		if (v == f) continue;
		dp[u][0] += std::max(dp[v][0] + fabs(l[u] - l[v]), dp[v][1] + fabs(l[u] - r[v]));
		dp[u][1] += std::max(dp[v][0] + fabs(r[u] - l[v]), dp[v][1] + fabs(r[u] - r[v]));
	}
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			G[i].clear(); dp[i][0] = dp[i][1] = 0;
			scanf("%d%d", &l[i], &r[i]);
		}
		for (int i = 1; i < n; i++) {
			int u, v; scanf("%d%d", &u, &v);
			G[u].push_back(v), G[v].push_back(u);
		}
		dfs(1, 0);
		printf("%lld\n", std::max(dp[1][0], dp[1][1]));
	}
	return 0;
}