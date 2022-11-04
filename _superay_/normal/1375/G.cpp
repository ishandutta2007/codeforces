#include <bits/stdc++.h>
using namespace std;
int n, cnt[2];
vector<int> G[200005];
void dfs(int u, int lst, int dep) {
	for (int i = 0; i < (int)G[u].size(); i++) {
		int v = G[u][i];
		if (v != lst) dfs(v, u, dep ^ 1);
	}
	cnt[dep]++;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0, 0);
	printf("%d\n", min(cnt[0], cnt[1]) - 1);
	return 0;
}