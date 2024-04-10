#include <iostream>
#include <vector>
using namespace std;

const int N = 100 * 1000 + 5;

bool mark[N];
int dis1[N];
int dis2[N];
int dis3[N];
vector <int> adj[N];

void dfs(int v, int dis[]) {
	for (auto u : adj[v]) {
		if (dis[u] == N) {
			dis[u] = dis[v] + 1;
			dfs(u, dis);
		}
	}
}
int main() {
	int n, m, d, u;
	cin >> n >> m >> d;
	for (int i = 0; i < m; i++) {
		cin >> u;
		mark[u] = true;
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	fill(dis1, dis1 + n + 1, N);
	fill(dis2, dis2 + n + 1, N);
	fill(dis3, dis3 + n + 1, N);
	dis1[u] = 0;
	dfs(u, dis1);
	int v = u;
	for (int i = 1; i <= n; i++) {
		if (mark[i] && dis1[i] > dis1[v]) {
			v = i;
		}
	}
	dis2[v] = 0;
	dfs(v, dis2);
	int w = v;
	for (int i = 1; i <= n; i++) {
		if (mark[i] && dis2[i] > dis2[w]) {
			w = i;
		}
	}
	dis3[w] = 0;
	dfs(w, dis3);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
	//	cout << i << " " << dis1[i] << " " << dis2[i] << " " << dis3[i] << endl;
	}
	for (int i = 1; i <= n; i++) {
		if (dis2[i] <= d && dis3[i] <= d) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}