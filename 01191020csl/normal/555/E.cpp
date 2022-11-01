#include<bits/stdc++.h>
using namespace std;
int read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
int vis[200001], num;
namespace graph {
	int head[200001], ver[400001], nxt[400001], sz;
	void addedge(int u, int v) {
		ver[++sz] = v, nxt[sz] = head[u], head[u] = sz;
		ver[++sz] = u, nxt[sz] = head[v], head[v] = sz;
	}
	int dfn[200001], low[200001], tot;
	int seq[200001], top;
	int id[200001];
	vector<int> scc[200001];
	void tarjan(int x, int fa) {
		dfn[x] = low[x] = ++tot;
		seq[++top] = x;
		for (int i = head[x]; i; i = nxt[i])
			if (i != fa) {
				if (!dfn[ver[i]]) tarjan(ver[i], i&1?i+1:i-1), low[x] = min(low[x], low[ver[i]]);
				else low[x] = min(low[x], dfn[ver[i]]);
			}
		if (dfn[x] == low[x]) {
			++num;
			while (seq[top] != x) {
				id[seq[top]] = num;
				scc[num].push_back(seq[top--]);
			}
			id[seq[top]] = num;
			scc[num].push_back(seq[top--]);
		}
	}
}
int head[200001], ver[400001], nxt[400001], sz;
void addedge(int u, int v) {
	ver[++sz] = v, nxt[sz] = head[u], head[u] = sz;
	ver[++sz] = u, nxt[sz] = head[v], head[v] = sz;
}
int fa[200001], dep[200001], size[200001], son[200001], tree[200001];
void dfs1(int x, int n) {
	tree[x] = n, size[x] = 1;
	for (int i = head[x]; i; i = nxt[i])
		if (fa[x] != ver[i]) {
			fa[ver[i]] = x;
			dep[ver[i]] = dep[x] + 1;
			dfs1(ver[i], n);
			size[x] += size[ver[i]];
			if (size[ver[i]] > size[son[x]]) son[x] = ver[i];
		}
}
int id[200001], top[200001], now;
void dfs2(int x, int t) {
	id[x] = ++now, top[x] = t;
	if (son[x]) dfs2(son[x], t);
	for (int i = head[x]; i; i = nxt[i])
		if (fa[x] != ver[i] && son[x] != ver[i])
			dfs2(ver[i], ver[i]);
}
struct node {
	int tag, maxn, minn;
}nd[1<<19];
void pushdown(int p) {
	if (!nd[p].tag) return;
	nd[p*2].tag = nd[p*2].maxn = nd[p*2].minn = nd[p].tag;
	nd[p*2+1].tag = nd[p*2+1].maxn = nd[p*2+1].minn = nd[p].tag;
	nd[p].tag = 0;
}
void modify(int p, int l, int r, int l0, int r0, int x) {
	if (l >= l0 && r <= r0) {
		nd[p].tag = nd[p].maxn = nd[p].minn = x;
		return;
	}
	pushdown(p);
	int mid = (l + r) / 2;
	if (l0 <= mid) modify(p * 2, l, mid, l0, r0, x);
	if (r0 > mid) modify(p * 2 + 1, mid + 1, r, l0, r0, x);
	nd[p].maxn = max(nd[p*2].maxn, nd[p*2+1].maxn);
	nd[p].minn = min(nd[p*2].minn, nd[p*2+1].minn);
}
int querymax(int p, int l, int r, int l0, int r0) {
	if (l >= l0 && r <= r0) return nd[p].maxn;
	pushdown(p);
	int mid = (l + r) / 2, ans = -1;
	if (l0 <= mid) ans = max(ans, querymax(p * 2, l, mid, l0, r0));
	if (r0 > mid) ans = max(ans, querymax(p * 2 + 1, mid + 1, r, l0, r0));
	return ans;
}
int querymin(int p, int l, int r, int l0, int r0) {
	if (l >= l0 && r <= r0) return nd[p].minn;
	pushdown(p);
	int mid = (l + r) / 2, ans = 1;
	if (l0 <= mid) ans = min(ans, querymin(p * 2, l, mid, l0, r0));
	if (r0 > mid) ans = min(ans, querymin(p * 2 + 1, mid + 1, r, l0, r0));
	return ans;
}
int main() {
	int n, m, q;
	n = read(), m = read(), q = read();
	for (int i = 1; i <= m; i++) {
		int u, v;
		u = read(), v = read();
		graph::addedge(u, v);
	}
	for (int i = 1; i <= n; i++) 
		if (!vis[i]) graph::tarjan(i, 0);
	for (int i = 1; i <= num; i++) {
		vis[i] = 1;
		for (int u : graph::scc[i])
			for (int j = graph::head[u]; j; j = graph::nxt[j]) {
				int v = graph::ver[j];
				if (!vis[graph::id[v]] && graph::id[v] > i) addedge(i, graph::id[v]);
				vis[graph::id[v]] = 1;
			}
		for (int u : graph::scc[i])
			for (int j = graph::head[u]; j; j = graph::nxt[j])
				vis[graph::id[graph::ver[j]]] = 0;
		vis[i] = 0;
	}
	int cnt = 0;
	for (int i = 1; i <= num; i++)
		if (!fa[i]) dfs1(i, ++cnt), dfs2(i, i);
	for (int i = 1; i <= q; i++) {
		int s, t;
		s = read(), t = read();
		s = graph::id[s], t = graph::id[t];
		if (s == t) continue;
		if (tree[s] != tree[t]) {
			puts("No");
			return 0;
		}
		int swp = 1;
		while (top[s] != top[t]) {
			if (dep[top[s]] < dep[top[t]]) swap(s, t), swp *= -1;
			int up = top[s];
			if (swp == 1 && querymin(1, 1, n, id[up], id[s]) == -1) {
				puts("No");
				return 0;
			}
			if (swp == -1 && querymax(1, 1, n, id[up], id[s]) == 1) {
				puts("No");
				return 0;
			}
			modify(1, 1, n, id[up], id[s], swp);
			s = fa[up];
		}
		if (s == t) continue;
		if (dep[s] < dep[t]) swap(s, t), swp *= -1;
		if (swp == 1 && querymin(1, 1, n, id[t]+1, id[s]) == -1) {
			puts("No"); 
			return 0;
		}
		if (swp == -1 && querymax(1, 1, n, id[t]+1, id[s]) == 1) {
			puts("No");
			return 0;
		}
		modify(1, 1, n, id[t]+1, id[s], swp);
	}
	puts("Yes");
	return 0;
}