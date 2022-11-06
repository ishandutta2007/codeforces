#include <bits/stdc++.h>
const int N = 2e5 + 5;
int T, n, a[N], ok[N], vis[N], rt[N], to[N], cnt;
std::vector<int> ans;
void dfs(int u) {
	vis[u] = 1; rt[u] = u;
	if (!vis[a[u]]) dfs(a[u]);
	rt[u] = rt[a[u]];
}
void Dfs(int u) {
	to[u] = a[u]; vis[u] = 1;
	if (!vis[a[u]]) Dfs(a[u]);
}
void DFS(int u) {
	ans.push_back(u); vis[u] = 1;
	if (!vis[a[u]]) DFS(a[u]);
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		std::fill(ok + 1, ok + n + 1, 1);
		std::fill(vis + 1, vis + n + 1, 0);
		std::fill(rt + 1, rt + n + 1, 0);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), ok[a[i]] = 0;
		ans.clear(); cnt = 0;
		for (int i = 1; i <= n; i++)
			if (!vis[i]) dfs(i);
		std::fill(vis + 1, vis + n + 1, 0);
		for (int i = 1; i <= n; i++)
			if (!vis[rt[i]]) Dfs(rt[i]);
		for (int i = 1; i <= n; i++)
			if (ok[i]) DFS(i);
		for (int i = 1; i < ans.size(); i++) to[ans[i - 1]] = ans[i];
		if (ans.size()) to[ans[ans.size() - 1]] = ans[0];
		if (ans.size() == 1) {
			// printf("%d %d\n", ans[0], a[ans[0]]);
			for (int i = 1; i <= n; i++)
				if (to[i] == a[ans[0]]) to[i] = ans[0];
			to[ans[0]] = a[ans[0]];
		}
		for (int i = 1; i <= n; i++) cnt += a[i] == to[i];
		printf("%d\n", cnt);
		for (int i = 1; i <= n; i++) printf("%d%c", to[i], " \n"[i == n]);
	}
	return 0;
}