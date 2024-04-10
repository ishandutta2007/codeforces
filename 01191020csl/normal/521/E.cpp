#include<bits/stdc++.h>
using namespace std;
int read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
void write(int num) {
	if (num >= 10) write(num / 10);
	putchar(num % 10 + '0');
}
int head[200001], ver[400001], nxt[400001], sz;
void addedge(int u, int v) {
	ver[++sz] = v, nxt[sz] = head[u], head[u] = sz;
	ver[++sz] = u, nxt[sz] = head[v], head[v] = sz;
}
int dfn[200001], low[200001], tot;
int stk[200001], vis[400001], top, num;
vector<int> scc[200001];
void tarjan(int x) {
	dfn[x] = low[x] = ++tot;
	stk[++top] = x, vis[x] = 1;
	for (int i = head[x]; i; i = nxt[i])
		if (!vis[ver[i]]) {
			tarjan(ver[i]), low[x] = min(low[x], low[ver[i]]);
			if (low[ver[i]] == dfn[x]) {
				++num;
				while (stk[top] != ver[i]) {
					vis[stk[top]] = 2;
					scc[num].push_back(stk[top--]);
				}
				vis[stk[top]] = 2, scc[num].push_back(stk[top--]);
				scc[num].push_back(x);
			}
		}
		else if (vis[ver[i]] == 1) low[x] = min(low[x], dfn[ver[i]]);
}
int fa[400001], dep[400001];
vector<int> edge[400001];
vector<pair<int, int> > tmp[200001];
int deg[200001];
void dfs(int x) {
	vis[x] = 1;
	for (int i : edge[x])
		if (fa[x] != i) {
			fa[i] = x, dep[i] = dep[x] + 1;
			dfs(i);
		}
}
int res[200001], len;
bool getroute(int x, int t, int op) {
	res[++len] = x;
	vis[x] = 1;
	if (op && x == t) return 1;
	for (int j : edge[x])
		if (!vis[j] || (len > 2 && j == t))
			if (getroute(j, t, 1)) return 1;
	--len;
	return 0;
}
bool findroute(int x) {
	res[++len] = x;
	if (vis[x] == 1) return 1;
	vis[x] = 2;
	for (int j : edge[x])
		if (vis[j] != 2)
			if (findroute(j)) return 1;
	--len;
	return 0;
}
int ans[200001], p;
void write() {
	int st = ans[1], ed = res[len];
	int p1 = 1;
	while (ans[p1] != ed) ++p1;
	write(p1);
	for (int i = 1; i <= p1; i++) putchar(' '), write(ans[i]);
	putchar('\n');
	write(p - p1 + 1);
	for (int i = p; i >= p1; i--) putchar(' '), write(ans[i]);
	putchar('\n');
	write(len + 1), putchar(' '), write(st);
	for (int i = 1; i <= len; i++) putchar(' '), write(res[i]);
	putchar('\n');
}
int main() {
	int n, m;
	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		int u, v;
		u = read(), v = read();
		addedge(u, v);
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i]) 
			tarjan(i), top = 0;
	for (int i = 1; i <= num; i++)
		if (scc[i].size() == 1) continue;
		else for (int j : scc[i])
			edge[j].push_back(i+n), edge[i+n].push_back(j);
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++)
		if (!vis[i]) dfs(i);
	for (int i = 1; i <= n; i++)
		for (int j = head[i]; j; j = nxt[j]) {
			int u = i, v = ver[j], id;
			if (u > v) continue;
			if (dep[u] >= dep[v]) id = fa[u] - n;
			else id = fa[v] - n;
			tmp[id].push_back(make_pair(u, v));
		}
	for (int i = 1; i <= num; i++) {
		if (tmp[i].size() <= scc[i].size()) continue;
		puts("YES");
		for (int j : scc[i]) vis[j] = 0, edge[j].clear();
		for (pair<int, int> j : tmp[i]) {
			int u = j.first, v = j.second;
			edge[u].push_back(v), edge[v].push_back(u);
			++deg[u], ++deg[v];
		}
		int u;
		for (int j : scc[i])
			if (deg[j] > 2) {
				u = j;
				break;
			}
		getroute(u, u, 0);
		p = len, vis[u] = 2, len = 0;
		for (int j = 1; j <= p; j++) ans[j] = res[j];
		for (int j : edge[u])
			if (j != ans[2] && j != ans[p-1]) {
				findroute(j);
				write();
				return 0;
			}
	}
	puts("NO");
}