#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 405;
int n, m, dist[N][N], eu[N * 2], ev[N * 2], fr[N][N], vis[N];
vector<int> G[N], F[N][N];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
		eu[i] = u;
		ev[i] = v;
	}
	for (int s = 1; s <= n; s++) {
		queue<int> que;
		for (int i = 1; i <= n; i++) dist[s][i] = -1;
		dist[s][s] = 0;
		que.push(s);
		while (!que.empty()) {
			int u = que.front(); que.pop();
			for (int v : G[u]) if (dist[s][v] == -1) {
				dist[s][v] = dist[s][u] + 1;
				que.push(v);
			}
		}
		for (int i = 1; i <= n; i++) fr[s][i] = 0;
		for (int i = 1; i <= m; i++) {
			if (dist[s][eu[i]] != dist[s][ev[i]]) {
				if (dist[s][eu[i]] > dist[s][ev[i]]) {
					if (!fr[s][eu[i]]) fr[s][eu[i]] = ev[i];
					else fr[s][eu[i]] = -1;
					F[s][eu[i]].push_back(i);
				} else {
					if (!fr[s][ev[i]]) fr[s][ev[i]] = eu[i];
					else fr[s][ev[i]] = -1;
					F[s][ev[i]].push_back(i);
				}
			}
		}
	}
	for (int s = 1; s <= n; s++) {
		for (int t = 1; t <= n; t++) {
			int u = t, flag = 0;
			for (int i = 1; i <= n; i++) vis[i] = 0;
			while (u != s) {
				vis[u] = 1;
				if (fr[s][u] == -1) { flag = 1; break; }
				u = fr[s][u];
			}
			if (flag) {
				printf("0%c", " \n"[t == n]);
				continue;
			}
			vis[s] = 1;
			int ans = 1;
			for (int u = 1; u <= n; u++) if (!vis[u]) {
				int c = 0;
				for (int i : F[s][u]) {
					int v = (eu[i] == u ? ev[i] : eu[i]);
					if (dist[t][v] < dist[t][u]) c++;
				}
				ans = 1ll * ans * c % mod;
			}
			printf("%d%c", ans, " \n"[t == n]);
		}
	}
	return 0;
}