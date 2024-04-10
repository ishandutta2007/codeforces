#include <bits/stdc++.h>
using std::min;
const int N = 4e5 + 5;
int n, m, a[N], b[N], s[N];
char getc() {
	char c;
	while (c = getchar(), c != '.' && c != '#') ;
	return c;
}
int ID(int x, int y) {
	return x * m + y;
}
std::vector<int> G[N];
void adde(int u, int v) {
	// printf("(%d,%d) (%d,%d)\n", u%m, u/m, v%m, v/m);
	G[u].push_back(v);
}
int low[N], dfn[N], st[N], scc[N], top = 0, dfs_clock = 0, scc_cnt = 0;
void tarjan(int u) {
	low[u] = dfn[u] = ++dfs_clock;
	st[++top] = u;
	for (int v : G[u]) {
		if (!dfn[v])
			tarjan(v), low[u] = min(low[u], low[v]);
		else if (!scc[v])
			low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		for (scc_cnt++;;) {
			int x = st[top--];
			scc[x] = scc_cnt;
			if (x == u) break;
		}
	}
}
int in[N];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = n - 1; ~i; i--)
		for (int j = 0; j < m; j++)
			a[ID(i, j)] = getc() == '#';
	for (int i = 0; i < m; i++)
		scanf("%d", &b[i]);
	for (int j = 0; j < m; j++)
		s[ID(0, j)] = a[ID(0, j)] ? 0 : -1;
	for (int i = 1; i < n; i++)
		for (int j = 0; j < m; j++)
			s[ID(i, j)] = a[ID(i, j)] ? i : s[ID(i - 1, j)];
	for (int j = 0; j < m; j++)
		for (int i = 0, k = -1; i < n; i++) {
			if (!a[ID(i, j)]) continue;
			if (k != -1) adde(ID(i, j), ID(k, j));//, puts("A");
			if (j && s[ID(i, j - 1)] != -1) adde(ID(i, j), ID(s[ID(i, j - 1)], j - 1));//, puts("B");
			if (j < m - 1 && s[ID(i, j + 1)] != -1) adde(ID(i, j), ID(s[ID(i, j + 1)], j + 1));//, puts("C");
			if (i < n - 1 && a[ID(i + 1, j)]) adde(ID(i, j), ID(i + 1, j));//, puts("D");
			k = i;
		}
	for (int i = 0; i < n * m; i++)
		if (a[i] && !scc[i]) tarjan(i);
	for (int u = 0; u < n * m; u++)
		for (int v : G[u])
			if (scc[u] != scc[v]) in[scc[v]] = 1;//, printf("(%d, %d)\n", scc[u], scc[v]);
/*
	for (int i = n - 1; ~i; i--)
		for (int j = 0; j < m; j++)
			printf("%d%c", scc[ID(i, j)], " \n"[j == m - 1]);
*/
	int ans = 0;
	for (int i = 1; i <= scc_cnt; i++) ans += in[i] == 0;
	printf("%d\n", ans);
	return 0;
}