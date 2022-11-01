#include<bits/stdc++.h>
using namespace std;
struct info {
	int a, b, typ;
}inf[200001];
bool operator<(info a, info b) {
	return a.a < b.a;
}
int head[200001], ver[400001], nxt[400001], sz;
void addedge(int u, int v) {
	ver[++sz] = v, nxt[sz] = head[u], head[u] = sz;
	ver[++sz] = u, nxt[sz] = head[v], head[v] = sz;
}
int vis[400001], f[200001], size[200001];
void dfs(int x, int dep) {
	vis[x] = 1, size[x] = 1, f[x] = inf[x].typ!=dep;
	for (int i = head[x]; i; i = nxt[i])
		if (!vis[ver[i]]) {
			dfs(ver[i], dep^1);
			size[x] += size[ver[i]];
			f[x] += f[ver[i]];
		}
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> inf[i].a >> inf[i].b;
		if (inf[i].a > inf[i].b) swap(inf[i].a, inf[i].b), inf[i].typ = 1;
		if (inf[i].a > n || inf[i].b <= n) {
			puts("-1");
			return 0;
		}
	}
	sort(inf + 1, inf + n + 1);
	for (int i = 1; i <= n; i++)
		vis[inf[i].b] = i;
	int p = n*2, q = n*2, last = 0;
	for (int i = 1; i <= n; i++) {
		if (inf[i].b == q) {
			while (q > n && vis[q] <= i) --q;
			continue;
		}
		if (p >= q) p = q, last = 0;
		else addedge(i, vis[last]), --p;
		if (inf[i].b > p) {
			puts("-1");
			return 0;
		}
		while (p > inf[i].b) addedge(i, vis[last=p--]);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			dfs(i, 0);
			ans += min(f[i], size[i]-f[i]);
		}
	cout << ans << endl;
}