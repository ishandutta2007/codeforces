#include<bits/stdc++.h>
using namespace std;
int read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
int head[200001], ver[400001], edge[400001], nxt[400001], sz;
void addedge(int u, int v, int w) {
	ver[++sz] = v, edge[sz] = w, nxt[sz] = head[u], head[u] = sz;
	ver[++sz] = u, edge[sz] = w, nxt[sz] = head[v], head[v] = sz;
}
int w[200001];
int size[200001];
int vis[200001], v0[200001];
void dfs1(int x) {
	size[x] = 1;
	v0[x] = 1;
	for (int i = head[x]; i; i = nxt[i])
		if (!vis[ver[i]] && !v0[ver[i]]) {
			dfs1(ver[i]);
			size[x] += size[ver[i]];
		}
	v0[x] = 0;
}
int centre, maxsize;
void dfs2(int x, int tot) {
	v0[x] = 1;
	int s = tot - size[x];
	for (int i = head[x]; i; i = nxt[i])
		if (!vis[ver[i]] && !v0[ver[i]]) {
			dfs2(ver[i], tot);
			s = max(s, size[ver[i]]);
		}
	if (s < maxsize) {
		maxsize = s;
		centre = x;
	}
	v0[x] = 0;
}
int dis[200001];
void dfsans(int x) {
	v0[x] = 1;
	for (int i = head[x]; i; i = nxt[i])
		if (!v0[ver[i]]) {
			dis[ver[i]] = dis[x] + edge[i];
			dfsans(ver[i]);
		}
	v0[x] = 0;
}
double df[200001];
void dfsd(int x) {
	df[x] = w[x] * sqrt(dis[x]);
	v0[x] = 1;
	for (int i = head[x]; i; i = nxt[i])
		if (!v0[ver[i]]) {
			dfsd(ver[i]);
			df[x] += df[ver[i]];
		}
	v0[x] = 0;
}
int res1, res2;
void solve(int x) {
	dfs1(x);
	if (size[x] == 1) {
		res1 = x;
		res2 = -1;
		return;
	}
	if (size[x] == 2) {
		res1 = x;
		for (int i = head[x]; i; i = nxt[i])
			if (!vis[ver[i]]) res2 = ver[i];
		return;
	}
	maxsize = 0x3f3f3f3f;
	dfs2(x, size[x]);
	int u = centre;
	dis[u] = 0, dfsans(u);
	dfsd(u);
	int dir = -1;
	for (int i = head[u]; i; i = nxt[i])
		if (!vis[ver[i]] && df[u] - 2 * df[ver[i]] < 0) dir = ver[i];
	if (dir == -1) {
		res1 = u;
		return;
	}
	for (int i = head[u]; i; i = nxt[i])
		if (!vis[ver[i]] && ver[i] != dir) vis[ver[i]] = 1;
	solve(dir);
}
int main() {;
	int n = read();
	for (int i = 1; i <= n; i++) w[i] = read();
	for (int i = 1; i < n; i++) {
		int u, v, w;
		u = read(), v = read(), w = read();
		addedge(u, v, w);
	}
	solve(1);
	int ans = res1;
	double dist = 0;
	dis[ans] = 0, dfsans(ans);
	for (int i = 1; i <= n; i++) dist += w[i] * sqrt(1ll*dis[i]*dis[i]*dis[i]);
	if (res2 > 0) {
		double tmp = 0;
		dis[res2] = 0, dfsans(res2);
		for (int i = 1; i <= n; i++) tmp += w[i] * sqrt(1ll*dis[i]*dis[i]*dis[i]);
		if (tmp < dist) dist = tmp, ans = res2;
	}
	cout << ans << ' ' << fixed << setprecision(8) << dist << endl;
}