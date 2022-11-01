#include<bits/stdc++.h>
using namespace std;
int head[2005], ver[200001], edge[200001], nxt[200001], sz;
void addedge(int u, int v, int w) {
	ver[++sz] = v, edge[sz] = w, nxt[sz] = head[u], head[u] = sz;
	ver[++sz] = u, edge[sz] = w, nxt[sz] = head[v], head[v] = sz;
}
void dijkstra(int n, int x, long long dis[]) {
	memset(dis, 0x3f, sizeof(long long)*(n+1));
	dis[x] = 0;
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	pq.push(make_pair(0, x));
	while (pq.size()) {
		int u = pq.top().second;
		long long d = pq.top().first;
		pq.pop();
		if (dis[u] != d) continue;
		for (int i = head[u]; i; i = nxt[i])
			if (dis[ver[i]] > dis[u] + edge[i]) {
				dis[ver[i]] = dis[u] + edge[i];
				pq.push(make_pair(dis[ver[i]], ver[i]));
			}
	}
}
long long dis[2][2005], p[2005], tmp[2005];
long long f[2005][2005][2], qa[2005], qb[2005], pa[2005], pb[2005], s[2005][2005];
int t[2005][2005];
int main() {
	int n, m;
	cin >> n >> m;
	int x, y;
	cin >> x >> y;
	for (int i = 1; i <= n; i++) cin >> p[i];
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		addedge(u, v, w);
	}
	dijkstra(n, x, dis[0]), dijkstra(n, y, dis[1]);
	memcpy(tmp, dis[0], sizeof(long long) * (n+1));
	sort(tmp + 1, tmp + n + 1);
	int l1 = unique(tmp + 1, tmp + n + 1) - tmp - 1;
	for (int i = 1; i <= n; i++) dis[0][i] = lower_bound(tmp + 1, tmp + l1 + 1, dis[0][i]) - tmp;
	memcpy(tmp, dis[1], sizeof(long long) * (n+1));
	sort(tmp + 1, tmp + n + 1);
	int l2 = unique(tmp + 1, tmp + n + 1) - tmp - 1;
	for (int i = 1; i <= n; i++) dis[1][i] = lower_bound(tmp + 1, tmp + l2 + 1, dis[1][i]) - tmp;
	for (int i = 1; i <= n; i++) t[dis[0][i]][dis[1][i]] += 1, s[dis[0][i]][dis[1][i]] += p[i];
	++l1, ++l2;
	for (int i = l1; i; i--)
		for (int j = l2; j; j--)
			t[i][j] += t[i][j+1], s[i][j] += s[i][j+1];
	for (int j = l2; j; j--)
		for (int i = l1; i; i--)
			t[i][j] += t[i+1][j], s[i][j] += s[i+1][j];
	for (int i = 1; i <= l2; i++) pa[i] = l1 + 1, qa[i] = 0x3f3f3f3f3f3f3f3f;
	for (int i = 1; i <= l1; i++) pb[i] = l2 + 1, qb[i] = 0x3f3f3f3f3f3f3f3f;
	for (int i = l1; i; i--)
		for (int j = l2; j; j--) {
			if (!t[i][j]) continue;
			while (t[pa[j]-1][j] < t[i][j]) --pa[j], qa[j] = min(qa[j], f[pa[j]][j][1]);
			f[i][j][0] = s[i][j] - qa[j];
			while (t[i][pb[i]-1] < t[i][j]) --pb[i], qb[i] = min(qb[i], f[i][pb[i]][0]);
			f[i][j][1] = s[i][j] - qb[i];
		}
	cerr << f[1][1][0] << endl;
	if (f[1][1][0] * 2 < s[1][1]) puts("Cry");
	else if (f[1][1][0] * 2 == s[1][1]) puts("Flowers");
	else puts("Break a heart");
}