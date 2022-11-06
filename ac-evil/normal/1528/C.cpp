#include <bits/stdc++.h>
const int N = 3e5 + 5;
int T, n, dfn[N], siz[N], dfs_clock, ans;
std::vector<int> Ga[N], Gb[N];
std::set<std::pair<int, int>> s;
void dfs(int u) {
	siz[u] = 1; dfn[u] = ++dfs_clock;
	for (int v : Gb[u])
		dfs(v), siz[u] += siz[v];
}
void Dfs(int u) {
	for (int v : Ga[u]) {
		std::pair<int, int> x = {dfn[v], dfn[v] + siz[v]}, y = {0, 0};
		auto it = s.lower_bound(x);
		if (it != s.begin()) {
			--it;
			if (it->second > dfn[v])
				y = *it, s.erase(it);
		}
		s.insert(x);
		ans = std::max(ans, (int)s.size());
		Dfs(v);
		s.erase(x);
		if (y.first) s.insert(y);
	}
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			Ga[i].clear(), Gb[i].clear();
		for (int i = 2; i <= n; i++) {
			int fa; scanf("%d", &fa);
			Ga[fa].push_back(i);
		}
		for (int i = 2; i <= n; i++) {
			int fa; scanf("%d", &fa);
			Gb[fa].push_back(i);
		}
		dfs_clock = 0; ans = 1; s = {{1, n + 1}};
		dfs(1); Dfs(1);
		printf("%d\n", ans);
	}
	return 0;
}