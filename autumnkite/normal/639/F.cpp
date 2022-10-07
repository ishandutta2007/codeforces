#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
char buf[1 << 23], *ps = buf, *pt = buf, pbuf[1 << 23], *pp = pbuf;
#define getchar() (ps == pt && (pt = (ps = buf) + fread(buf, 1, 1 << 23, stdin), ps == pt) ? EOF : *ps++)
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
const int N = 300005;
int n, m, q, X[N], Y[N], nn, Col[N], cnt, col[N];
int edge, to[N << 1], pr[N << 1], hd[N];
void addedge(int u, int v){
	to[edge] = v, pr[edge] = hd[u], hd[u] = edge++;
}
namespace contract{
	int idx, dfn[N], low[N], top, sta[N], vis[N];
	void tarjan(int u, int fe = -1){
		dfn[u] = low[u] = ++idx, sta[++top] = u, vis[u] = 1;
		for (register int i = hd[u], v; ~i; i = pr[i]){
			if (!dfn[v = to[i]] && v) tarjan(v, i), low[u] = std :: min(low[u], low[v]);
			else if (v && (i ^ 1) != fe) low[u] = std :: min(low[u], dfn[v]);
		}
		if (dfn[u] == low[u]){
			sta[top + 1] = -1, ++cnt;
			while (sta[top + 1] != u) col[sta[top]] = cnt, --top;
		}
	}
	void Main(int n, int *p){
		idx = top = cnt = 0;
		for (register int i = 1; i <= n; ++i) dfn[p[i]] = 0;
		for (register int i = 1; i <= n; ++i)
			if (!dfn[p[i]] && p[i]) tarjan(p[i]);
	}
}
namespace tree{
	int idx, dfn[N], dep[N], fa[N][19];
	void dfs(int u){
		dfn[u] = ++idx, dep[u] = dep[fa[u][0]] + 1;
		for (register int i = 1; i <= 18; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
		for (register int i = hd[u], v; ~i; i = pr[i])
			if ((v = to[i]) != fa[u][0]) fa[v][0] = u, dfs(v);
	}
	void init(){
		idx = 0;
		for (register int i = 1; i <= nn; ++i) if (!dfn[i]) dfs(i);
	}
	int LCA(int u, int v){
		if (dep[u] < dep[v]) std :: swap(u, v);
		for (register int i = 18; ~i; --i)
			if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
		if (u == v) return u;
		for (register int i = 18; ~i; --i)
			if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
		return fa[u][0];
	}
}
using tree :: dfn;
using tree :: LCA;
int top, sta[N], dn, dm, S[N], k, p[N * 3], vis[N], tot, id[N];
void insert(int u){
	if (!top) return sta[++top] = u, void(0);
	int x = sta[top], lca = LCA(x, u), y;
	if (lca == x) return sta[++top] = u, void(0);
	while (top > 1 && dfn[y = sta[top - 1]] > dfn[lca])
		addedge(x, y), addedge(y, x), x = sta[--top];
	addedge(x, lca), addedge(lca, x), --top;
	if (!top || sta[top] != lca) sta[++top] = lca;
	sta[++top] = u;
}
void get_nodes(int u){
	vis[u] = 1, id[++tot] = u;
	for (register int i = hd[u], v; ~i; i = pr[i])
		if (!vis[v = to[i]]) get_nodes(v);
}
int main(){
	n = read(), m = read(), q = read();
	for (register int i = 1; i <= n; ++i) hd[i] = -1, id[i] = i;
	for (register int i = 1; i <= m; ++i)
		X[i] = read(), Y[i] = read(), addedge(X[i], Y[i]), addedge(Y[i], X[i]);
	contract :: Main(n, id);
	for (register int i = 1; i <= n; ++i) Col[i] = col[i];
	nn = cnt, edge = 0;
	for (register int i = 1; i <= nn; ++i) hd[i] = -1;
	for (register int i = 1; i <= m; ++i)
		if (Col[X[i]] != Col[Y[i]]) addedge(Col[X[i]], Col[Y[i]]), addedge(Col[Y[i]], Col[X[i]]);
	tree :: init(), edge = 0;
	for (register int i = 1; i <= nn; ++i) hd[i] = -1;
	int R = 0;
	for (register int T = 1; T <= q; ++T){
		dn = k = read(), dm = read();
		int x, y;
		for (register int i = 1; i <= k; ++i)
			p[i] = S[i] = Col[(read() + R - 1) % n + 1];
		for (register int i = 1; i <= dm; ++i){
			x = Col[(read() + R - 1) % n + 1], y = Col[(read() + R - 1) % n + 1];
			addedge(x, y), addedge(y, x), p[++k] = x, p[++k] = y;
		}
		std :: sort(p + 1, p + 1 + k, [=](int u, int v){
			return dfn[u] < dfn[v];
		});
		k = std :: unique(p + 1, p + 1 + k) - p - 1;
		top = 0;
		for (register int i = 1; i <= k; ++i) insert(p[i]);
		while (top > 1) x = sta[top], y = sta[top - 1], addedge(x, y), addedge(y, x), --top;
		tot = 0, get_nodes(sta[1]);
		contract :: Main(tot, id);
		bool flag = 1;
		for (register int i = 2; i <= dn; ++i)
			if (col[S[i]] != col[S[i - 1]]){ flag = 0; break; }
		if (flag) R = (R + T) % n, puts("YES");
		else puts("NO");
		edge = 0, hd[0] = -1;
		for (register int i = 1; i <= tot; ++i) hd[id[i]] = -1, vis[id[i]] = 0;
	}
}