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
#define N 8005
#define M 16000005
int n, m;
char a[2005][2005], b[2005][2005], c[2005], tmp[2005];
int edge, to[M], pr[M], hd[N];
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
std :: vector<int> ans;
int main(){
	n = read();
	for (register int i = 0; i < n; ++i) scanf("%s", a[i]);
	for (register int i = 0; i < n; ++i) scanf("%s", b[i]);
	scanf("%s", c);
	for (register int i = 0; i < n; ++i)
		for (register int j = 0; j < n; ++j){
			if (c[j] ^ a[i][j] ^ b[i][j] ^ '0')
				if (c[i] == '1') addedge(i << 1 | 1, (n << 1) + (j << 1 | 1));
				else addedge(i << 1 | 1, i << 1);
			else
				if (c[i] == '1') addedge(i << 1 | 1, (n << 1) + (j << 1));
			if (a[i][j] ^ b[i][j])
				if (c[i] == '1') addedge(i << 1, (n << 1) + (j << 1 | 1));
				else addedge(i << 1, i << 1 | 1);
			else
				if (c[i] == '1') addedge(i << 1, (n << 1) + (j << 1));
		}
	for (register int j = 0; j < n; ++j)
		for (register int i = 0; i < n; ++i){
			if (c[i] ^ a[i][j] ^ b[i][j] ^ '0')
				if (c[j] == '1') addedge((n << 1) + (j << 1 | 1), i << 1 | 1);
				else addedge((n << 1) + (j << 1 | 1), (n << 1) + (j << 1));
			else
				if (c[j] == '1') addedge((n << 1) + (j << 1 | 1), i << 1);
			if (a[i][j] ^ b[i][j])
				if (c[j] == '1') addedge((n << 1) + (j << 1), i << 1 | 1);
				else addedge((n << 1) + (j << 1), (n << 1) + (j << 1 | 1));
			else
				if (c[j] == '1') addedge((n << 1) + (j << 1), i << 1);
		}
	for (register int i = 0; i < (n << 2); ++i)
		if (!dfn[i]) tarjan(i);
	for (register int i = 0; i < (n << 1); ++i)
		if (col[i << 1] == col[i << 1 | 1]) return puts("-1"), 0;
		else if (col[i << 1 | 1] < col[i << 1]) ans.push_back(i);
	printf("%d\n", ans.size());
	for (int v : ans)
		if (v < n) printf("row %d\n", v);
		else printf("col %d\n", v - n);
}