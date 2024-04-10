#include<bits/stdc++.h>
using namespace std;
int read() {
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	int num = 0;
	while (isdigit(c)) {
		num = num * 10 + c - '0';
		c = getchar();
	}
	return num;
}
int l[100001], r[100001];
int head[100001], ver[200001], nxt[200001], sz;
void addedge(int u, int v) {
	ver[++sz] = v, nxt[sz] = head[u], head[u] = sz;
	ver[++sz] = u, nxt[sz] = head[v], head[v] = sz;
}
int fa[100001];
long long f[100001], g[100001];
void dfs(int x) {
	f[x] = g[x] = 0;
	for (int i = head[x]; i; i = nxt[i])
		if (fa[x] != ver[i]) {
			fa[ver[i]] = x, dfs(ver[i]);
			f[x] += max(f[ver[i]] + abs(l[ver[i]]-l[x]), g[ver[i]] + abs(r[ver[i]]-l[x]));
			g[x] += max(f[ver[i]] + abs(l[ver[i]]-r[x]), g[ver[i]] + abs(r[ver[i]]-r[x]));
		}
}
int main() {
	int t = read();
	while (t--) {
		int n = read();
		for (int i = 1; i <= n; i++) l[i] = read(), r[i] = read();
		for (int i = 1; i < n; i++) {
			int u = read(), v = read();
			addedge(u, v);
		}
		dfs(1);
		cout << max(f[1], g[1]) << endl;
		for (int i = 1; i <= n; i++) head[i] = fa[i] = 0;
		sz = 0;
	}
}