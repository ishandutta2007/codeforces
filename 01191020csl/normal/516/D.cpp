#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
int head[100010], ver[200010], edge[200010], nxt[200010], sz;
void addedge(int u, int v, int w) {
	ver[++sz] = v, edge[sz] = w, nxt[sz] = head[u], head[u] = sz;
	ver[++sz] = u, edge[sz] = w, nxt[sz] = head[v], head[v] = sz;
}
void remove(int u, int v) {
	if (ver[head[u]] == v) {
		head[u] = nxt[head[u]];
		return;
	}
	for (int i = head[u]; nxt[i]; i = nxt[i])
		if (ver[nxt[i]] == v) {
			nxt[i] = nxt[nxt[i]];
			return;
	}
}
int fa[100010];
long long dis[100010];
int u, vis[100010];
void dfs1(int x) {
	vis[x] = 1;
	if (dis[x] > dis[u]) u = x;
	for (int i = head[x]; i; i = nxt[i])
		if (!vis[ver[i]]) {
			dis[ver[i]] = dis[x] + edge[i];
			dfs1(ver[i]);
		}
	vis[x] = 0;
}
int v;
long long len = -1;
void dfs2(int x) {
	if (dis[x] > len) {
		len = dis[x];
		v = x;
	}
	for (int i = head[x]; i; i = nxt[i])
		if (fa[x] != ver[i]) {
			fa[ver[i]] = x;
			dis[ver[i]] = dis[x] + edge[i];
			dfs2(ver[i]);
		}
}
void dfs3(int x) {
	vis[x] = 1;
	for (int i = head[x]; i; i = nxt[i])
		if (!vis[ver[i]]) {
			fa[ver[i]] = x;
			dis[ver[i]] = dis[x] + edge[i];
			dfs3(ver[i]);
		}
	vis[x] = 0;
}
struct point {
	long long dis;
	int id;
}pt[100010];
bool operator<(const point &a, const point &b) {
	return a.dis < b.dis;
}
int f[100010], size[100010], ans[100010];
int getfa(int x) {
	if (!f[x]) return x;
	return f[x] = getfa(f[x]);
}
void link(int x, int y) {
	x = getfa(x), y = getfa(y);
	if (x == y) return;
	if (size[x] > size[y]) swap(x, y);
	f[x] = y, size[y] += size[x], ans[y] += ans[x];
}
int main() {
	int n = read();
	for (int i = 1; i < n; i++) {
		int u, v, w;
		u = read(), v = read(), w = read();
		addedge(u, v, w * 2);
	}
	dfs1(1), dis[u] = 0, dfs2(u);
	while (dis[fa[v]] > len / 2) v = fa[v];
	if (dis[fa[v]] == len / 2) addedge(n + 1, fa[v], 0);
	else {
		remove(v, fa[v]), remove(fa[v], v);
		addedge(n + 1, v, dis[v] - len/2), addedge(n + 1, fa[v], len/2 - dis[fa[v]]);
	}
	dfs3(n + 1);
	for (int i = 1; i <= n; i++) pt[i].dis = dis[i], pt[i].id = i;
	sort(pt + 1, pt + n + 1);
	int q = read();
	for (int i = 1; i <= q; i++) {
		long long l;
		cin >> l;
		l *= 2;
		int res = 0, po = n;
		for (int j = n; j >= 1; j--) {
			int u = pt[j].id;
			f[u] = 0, size[u] = ans[u] = 1;
			for (int k = head[u]; k; k = nxt[k])
				if (fa[u] != ver[k]) link(u, ver[k]);
			while (po && pt[po].dis > pt[j].dis + l) --ans[getfa(pt[po--].id)];
			res = max(res, ans[getfa(u)]);
		}
		size[n+1] = 1, ans[n+1] = 0;
		for (int j = head[n+1]; j; j = nxt[j]) link(n + 1, ver[j]);
		cout << max(res, ans[getfa(n+1)]) << endl;
	}
}