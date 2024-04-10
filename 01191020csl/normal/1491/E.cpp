#include<bits/stdc++.h>
using namespace std;
int head[200001], ver[400001], vis[400001], nxt[400001], sz = 1;
void addedge(int u, int v) {
	ver[++sz] = v, nxt[sz] = head[u], head[u] = sz;
	ver[++sz] = u, nxt[sz] = head[v], head[v] = sz;
}
int f[30];
int size[200001], v0[200001];
int dfs(int x, int res1, int res2) {
	int ret = -1;
	size[x] = 1, v0[x] = 1;
	for (int i = head[x]; i; i = nxt[i])
		if (!vis[i] && !v0[ver[i]]) {
			int tmp = dfs(ver[i], res1, res2);
			if (ret == -1) ret = tmp;
			size[x] += size[ver[i]];
			if (size[ver[i]] == res1)
				ret = i;
			if (size[ver[i]] == res2)
				ret = i ^ 1;
		}
	v0[x] = 0;
	return ret;
}
bool work(int x, int p) {
	if (p <= 1) return 1;
	int u = dfs(x, f[p-2], f[p-1]);
	if (u == -1) return 0;
	vis[u] = vis[u^1] = 1;
	return work(ver[u], p-2) && work(ver[u^1], p-1);
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		addedge(u, v);
	}
	if (n == 1) {
		puts("YES");
		return 0;
	}
	f[0] = f[1] = 1;
	for (int i = 2; i < 30; i++) {
		f[i] = f[i-1] + f[i-2];
		if (f[i] > n) {
			puts("NO");
			break;
		}
		if (f[i] == n) {
			if (work(1, i)) puts("YES");
			else puts("NO");
			break;
		}
	}
}