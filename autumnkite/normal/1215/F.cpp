#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 1600005
#define M 4000005
int n, m, q1, q2, l[N], r[N], ansf;
int edge, to[M], pr[M], hd[N];
std :: vector<int> ans;
void addedge(int u, int v){
	to[++edge] = v, pr[edge] = hd[u], hd[u] = edge;
}
int idx, dfn[N], low[N], top, sta[N], vis[N], cnt, col[N];
void tarjan(int u){
	dfn[u] = low[u] = ++idx, sta[++top] = u, vis[u] = 1;
	for (register int i = hd[u], v; i; i = pr[i])
		if (!dfn[v = to[i]]) tarjan(v), low[u] = std :: min(low[u], low[v]);
		else if (vis[v]) low[u] = std :: min(low[u], dfn[v]);
	if (dfn[u] == low[u]){
		++cnt, sta[top + 1] = -1;
		while (sta[top + 1] != u) col[sta[top]] = cnt, vis[sta[top--]] = 0;
	}
}
int main(){
	q1 = read(), n = read(), m = read(), q2 = read();
	for (register int i = 1; i < m; ++i)
		addedge((n << 1) + i - 1, (n << 1) + i), addedge((n << 1) + m + i, (n << 1) + m + i - 1);
	for (register int i = 1; i <= q1; ++i){
		int x = read() - 1, y = read() - 1;
		addedge(x << 1, y << 1 | 1), addedge(y << 1, x << 1 | 1);
	}
	for (register int i = 0; i < n; ++i){
		l[i] = read() - 1, r[i] = read() - 1;
		if (l[i] > 0) addedge(i << 1 | 1, (n << 1) + m + l[i] - 1);
		if (r[i] < m - 1) addedge(i << 1 | 1, (n << 1) + r[i] + 1);
		addedge((n << 1) + l[i], i << 1), addedge((n << 1) + m + r[i], i << 1);
	}
	for (register int i = 1; i <= q2; ++i){
		int x = read() - 1, y = read() - 1;
		addedge(x << 1 | 1, y << 1), addedge(y << 1 | 1, x << 1);
	}
	for (register int i = 0; i < (n << 1) + (m << 1); ++i)
		if (!dfn[i]) tarjan(i);
	for (register int i = 0; i < n; ++i)
		if (col[i << 1] == col[i << 1 | 1]) return puts("-1"), 0;
	for (register int i = 0; i < n; ++i)
		if (col[i << 1 | 1] < col[i << 1]) ans.push_back(i), ansf = std :: max(ansf, l[i]);
	printf("%d %d\n", ans.size(), ansf + 1);
	for (int v : ans) printf("%d ", v + 1);
}