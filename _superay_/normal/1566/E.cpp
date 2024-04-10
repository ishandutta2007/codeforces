#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, a[N];
vector<int> G[N];
void dfs(int u, int lst) {
	int has = 0;
	for (int v : G[u]) if (v != lst) {
		dfs(v, u);
		if (a[v] == 0) has = 1;
	}
	if (u == 1) a[u] = -1;
	else a[u] = has;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) G[i].clear();
		for (int i = 1; i < n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1, 0);
		int has = 0;
		for (int v : G[1]) if (!a[v]) has = 1;
		int cnt = 0;
		for (int u = 2; u <= n; u++) if (a[u]) cnt++;
		printf("%d\n", n - cnt * 2 - has);
	}
	return 0;
}