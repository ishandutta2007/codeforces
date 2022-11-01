#include<bits/stdc++.h>
using namespace std;
struct edge {
	int u, v, w;
}e[200001];
bool operator<(edge a, edge b) {
	return a.w < b.w;
}
int fa[200001];
int getfa(int x) {
	if (!fa[x]) return x;
	return fa[x] = getfa(fa[x]);
}
int w0[1001][1001], tot;
edge e0[1001], e1[1001];
void solve1(int n, int m) {
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		int u = e[i].u, v = e[i].v;
		w0[u][v] = w0[v][u] = 1;
		u = getfa(u), v = getfa(v);
		if (u != v) fa[u] = v, e0[++cnt] = e[i];
	}
	++cnt, e0[cnt].w = tot;
	sort(e0 + 1, e0 + cnt + 1);
	int c2 = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (!w0[i][j]) ++c2, e1[c2].u = i, e1[c2].v = j;
	long long ans = 0x3f3f3f3f3f3f3f3f;
	for (int i = 1; i <= c2; i++) {
		long long now = 0;
		for (int j = 1; j <= n; j++) fa[j] = 0;
		for (int j = 1; j <= c2; j++)
			if (i != j) {
				int u = e1[j].u, v = e1[j].v;
				u = getfa(u), v = getfa(v);
				if (u != v) fa[u] = v;
			}
		for (int j = 1; j <= cnt; j++) {
			int u = e0[j].u, v = e0[j].v, w = e0[j].w;
			if (!u) u = e1[i].u, v = e1[i].v, w = tot;
			u = getfa(u), v = getfa(v);
			if (u != v) fa[u] = v, now += w;
		}
		ans = min(ans, now);
	}
	cout << ans << endl;
}
vector<int> lk[200001];
int vis[200001], tmp[200001];
set<int> v0;
void solve2(int n, int m) {
	for (int i = 1; i <= m; i++) {
		lk[e[i].u].push_back(e[i].v);
		lk[e[i].v].push_back(e[i].u);
	}
	for (int i = 1; i <= n; i++) v0.insert(i);
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		queue<int> q;
		q.push(i), vis[i] = 1;
		while (q.size()) {
			int u = q.front();
			q.pop();
			if (u != i) fa[u] = i;
			for (int j : lk[u]) {
				set<int>::iterator it = v0.find(j);
				if (it != v0.end()) tmp[j] = 1, v0.erase(j);
			}
			for (int j : v0) vis[j] = 1, q.push(j);
			v0.clear();
			for (int j : lk[u])
				if (tmp[j]) v0.insert(j), tmp[j] = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		int u = e[i].u, v = e[i].v;
		u = getfa(u), v = getfa(v);
		if (u != v) fa[u] = v, ans += e[i].w;
	}
	cout << ans << endl;
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> e[i].u >> e[i].v >> e[i].w, tot ^= e[i].w;
	sort(e + 1, e + m + 1);
	if (1ll*n*(n-1)/2-m < n) solve1(n, m);
	else solve2(n, m);
}