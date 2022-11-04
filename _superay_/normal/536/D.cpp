#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int n, m, X[N], Y[N], p[N], T[N][N];
long long S[N][N], dp[N][N][2], f0[N][N], f1[N][N];
long long dis1[N], dis2[N];
vector<pair<int, int> > G[N];
inline void Dijk(int s, long long *dis) {
	priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > que;
	for (int i = 1; i <= n; i++) dis[i] = 1e18;
	dis[s] = 0;
	que.emplace(dis[s], s);
	while (!que.empty()) {
		auto P = que.top(); que.pop();
		int u = P.second;
		if (dis[u] != P.first) continue;
		for (auto &e : G[u]) {
			int v = e.first;
			if (dis[v] > dis[u] + e.second) {
				dis[v] = dis[u] + e.second;
				que.emplace(dis[v], v);
			}
		}
	}
}
int main() {
	int s, t;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		G[u].emplace_back(v, w);
		G[v].emplace_back(u, w);
	}
	Dijk(s, dis1);
	Dijk(t, dis2);
	vector<long long> v1, v2;
	v1.push_back(-1), v2.push_back(-1);
	for (int i = 1; i <= n; i++) {
		v1.push_back(dis1[i]);
		v2.push_back(dis2[i]);
	}
	sort(v1.begin(), v1.end());
	v1.resize(unique(v1.begin(), v1.end()) - v1.begin());
	sort(v2.begin(), v2.end());
	v2.resize(unique(v2.begin(), v2.end()) - v2.begin());
	for (int i = 1; i <= n; i++) {
		X[i] = lower_bound(v1.begin(), v1.end(), dis1[i]) - v1.begin();
		Y[i] = lower_bound(v2.begin(), v2.end(), dis2[i]) - v2.begin();
		S[X[i]][Y[i]] += p[i];
		T[X[i]][Y[i]]++;
	}
	for (int i = n; i >= 1; i--) {
		for (int j = n; j >= 1; j--) {
			S[i][j] += S[i][j + 1];
			T[i][j] += T[i][j + 1];
		}
	}
	for (int i = n; i >= 1; i--) {
		for (int j = n; j >= 1; j--) {
			S[i][j] += S[i + 1][j];
			T[i][j] += T[i + 1][j];
		}
	}
	memset(f0, 0x3f, sizeof(f0));
	memset(f1, 0x3f, sizeof(f1));
	for (int i = n; i >= 1; i--) {
		for (int j = n; j >= 1; j--) {
			if (!T[i][j]) {
				dp[i][j][0] = dp[i][j][1] = 0;
				continue;
			}
			f0[i][j] = f0[i + 1][j];
			if (T[i][j] > T[i + 1][j]) {
				for (int k = i; k <= n && T[k + 1][j] == T[i + 1][j]; k++) {
					f0[i][j] = min(f0[i][j], dp[k + 1][j][1]);
				}
			}
			dp[i][j][0] = S[i][j] - f0[i][j];
			f1[i][j] = f1[i][j + 1];
			if (T[i][j] > T[i][j + 1]) {
				for (int k = j; k <= n && T[i][k + 1] == T[i][j + 1]; k++) {
					f1[i][j] = min(f1[i][j], dp[i][k + 1][0]);
				}
			}
			dp[i][j][1] = S[i][j] - f1[i][j];
		}
	}
	long long t1 = dp[1][1][0], t2 = S[1][1] - t1;
	if (t1 == t2) puts("Flowers");
	else if (t1 > t2) puts("Break a heart");
	else puts("Cry");
	return 0;
}