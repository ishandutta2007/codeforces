#include<bits/stdc++.h>
using namespace std;
int head[300001], edge[600001], ver[600001], nxt[600001], sz;
void addedge(int u, int v, int w) {
	ver[++sz] = v, edge[sz] = w, nxt[sz] = head[u], head[u] = sz;
	ver[++sz] = u, edge[sz] = w, nxt[sz] = head[v], head[v] = sz;
}
long long a[300001];
int deg[300001];
int fa[300001];
int getfa(int x) {
	return fa[x] ? fa[x] = getfa(fa[x]) : x;
}
int main() {
	int n, m, x;
	long long sum = 0;
	cin >> n >> m >> x;
	for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
	if (sum < 1ll*(n-1)*x) {
		puts("NO");
		return 0;
	}
	puts("YES");
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		int u0 = getfa(u), v0 = getfa(v);
		if (u0 == v0) continue;
		++deg[u], ++deg[v], fa[u0] = v0;
		addedge(u, v, i);
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (deg[i] == 1) q.push(i);
	vector<int> ans;
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (int i = head[u]; i; i = nxt[i])
			if (deg[ver[i]]) {
				--deg[ver[i]], --deg[u];
				if (a[u] <= x) ans.push_back(edge[i]);
				else cout << edge[i] << endl, a[ver[i]] += a[u] - x;
				if (deg[ver[i]] == 1) q.push(ver[i]);
			}
	}
	reverse(ans.begin(), ans.end());
	for (int i : ans) cout << i << endl;
}