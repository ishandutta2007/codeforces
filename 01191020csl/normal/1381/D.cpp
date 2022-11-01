#include<bits/stdc++.h>
using namespace std;
int head[100001], ver[200001], nxt[200001], sz;
void addedge(int u, int v) {
	ver[++sz] = v, nxt[sz] = head[u], head[u] = sz;
	ver[++sz] = u, nxt[sz] = head[v], head[v] = sz;
}
int fa[100001], dep[100001];
int m1[100001], m2[100001], m3[100001];
void dfs(int x) {
	m1[x] = m2[x] = m3[x] = 0;
	for (int i = head[x]; i; i = nxt[i])
		if (fa[x] != ver[i]) {
			fa[ver[i]] = x;
			dep[ver[i]] = dep[x] + 1;
			dfs(ver[i]);
			if (m1[ver[i]] + 1 > m1[x]) m3[x] = m2[x], m2[x] = m1[x], m1[x] = m1[ver[i]] + 1;
			else if (m1[ver[i]] + 1 > m2[x]) m3[x] = m2[x], m2[x] = m1[ver[i]] + 1;
			else if (m1[ver[i]] + 1 > m3[x]) m3[x] = m1[ver[i]] + 1;
		}
}
int res[100001];
void dfs2(int x, int tmp) {
	if (!fa[x] || tmp < m3[x]) res[x] = m3[x];
	else if (tmp < m2[x]) res[x] = tmp;
	else res[x] = m2[x];
	for (int i = head[x]; i; i = nxt[i])
		if (fa[x] != ver[i]) dfs2(ver[i], max(tmp, m1[ver[i]]+1==m1[x]?m2[x]:m1[x]) + 1);
}
int vis[100001];
int seq[100001], dis[100001];
void dfs3(int x) {
	vis[x] = 1, dis[x] = 0;
	for (int i = head[x]; i; i = nxt[i])
		if (!vis[ver[i]]) {
			dfs3(ver[i]);
			dis[x] = max(dis[x], dis[ver[i]]);
		}
	++dis[x];
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;
		for (int i = 1; i <= n; i++) head[i] = fa[i] = vis[i] = 0;
		sz = 0;
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			addedge(u, v);
		}
		dep[a] = 0, dfs(a), dfs2(a, 0);
		int b0 = b, tot = 0;
		while (b0) vis[b0] = 1, seq[++tot] = b0, b0 = fa[b0];
		int l = 1, r = tot;
		int l0 = 1, r0 = tot;
		do {
			while (l <= l0 && l <= r) dfs3(seq[l]), r0 = min(r0, tot - dis[seq[l]] + l), ++l;
			while (r >= r0 && l <= r) dfs3(seq[r]), l0 = max(l0, r - (tot - dis[seq[r]])), --r;
		} while (l <= r && (l <= l0 || r >= r0));
		while (l <= r) vis[seq[l++]] = 0;
		bool flag = 0;
		for (int i = 1; i <= n; i++)
			if (vis[i] && res[i] >= tot - 1) {
				puts("YES");
				flag = 1;
				break;
			}
		if (!flag) puts("NO");
	}
}