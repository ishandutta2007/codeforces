#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 105;

vector <int> adj[N];
vector <int> vec[N];
int dis[N][N];
bool es[N][N];
int ans[N];
int st[N], ed[N];
bool mark[N];
int d[N];
queue <int> q;

void dfs(int v, int d) {
	if (mark[v] || ans[v] < d) {
		return;
	}
	mark[v] = true;
	for (auto u : adj[v]) {
		dfs(u, d);
	}
}

int main() {
	int n, m, a, b, k;
	cin >> n >> m >> a >> b;
	for (int i = 1; i <= n; i++) {
		ans[i] = N;
		for (int j = 1; j < i; j++) {
			dis[i][j] = N;
			dis[j][i] = N;
		}
	}
	ans[b] = 0;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		dis[u][v] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << "70 " << i << " " << j << " " << dis[i][j] << endl;
//		}
//	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int u, v;
		cin >> u >> v;
		st[i] = u;
		ed[i] = v;
		if (dis[u][v] == N) {
			continue;
		}
		for (int j = 0; j <= n; j++) {
			vec[j].clear();
		}
		for (int j = 1; j <= n; j++) {
			if (dis[u][j] + dis[j][v] == dis[u][v]) {
				vec[dis[u][j]].push_back(j);
			}
		}
		for (int j = 0; j <= n; j++) {
			if (vec[j].size() == 1) {
				es[i][vec[j][0]] = true;
			//	cout << "71 " << i << " " << vec[j][0] << endl;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			fill(d, d + n + 1, N);
			d[j] = 0;
			q.push(j);
			while (q.size()) {
				int v = q.front();
				q.pop();
				for (auto u : adj[v]) {
					if (ans[u] < i) {
						continue;
					}
					if (d[u] == N) {
						d[u] = d[v] + 1;
						q.push(u);
					} 
				}
			}
			for (int q = 0; q < k; q++) {
				if (es[q][j] && dis[j][ed[q]] < d[ed[q]] && ans[j] == N) {
				//	cout << "72 " << i << " " << j << " " << d[ed[q]] << endl;
					ans[j] = i;
				}
			}
		}
	}
	if (ans[a] == N) {
		cout << -1;
	}
	else {
		cout << ans[a];
	}
	return 0;
}