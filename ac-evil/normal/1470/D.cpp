#include <bits/stdc++.h>
#define pb push_back
using std::vector;
const int N = 300005;
int T, n, m;
vector<int> e[N], ans;
int col[N], vis[N];
void dfs(int u) {
	vis[u] = 1;
	if (col[u] == -1) {
		col[u] = 1; ans.pb(u);
		for (int i = 0; i < e[u].size(); i++) col[e[u][i]] = 0;
	}
	for (int i = 0; i < e[u].size(); i++)
		if (!vis[e[u][i]]) dfs(e[u][i]);
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m); ans.clear();
		for (int i = 1; i <= n; i++) e[i].clear(), col[i] = -1, vis[i] = 0;
		for (int i = 1; i <= m; i++) {
			int u, v; scanf("%d%d", &u, &v);
			e[u].pb(v), e[v].pb(u);
		}
		dfs(1);
		int ok = 1;
		for (int i = 1; i <= n; i++) if (!vis[i]) { ok = 0; break; }
		sort(ans.begin(), ans.end());
		if (ok) {
			puts("YES");
			printf("%d\n", ans.size());
			for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
			puts("");
		} else puts("NO");
	}
	return 0;
}