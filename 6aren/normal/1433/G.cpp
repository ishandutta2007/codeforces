#include<bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define x first
#define y second

const int N = 1005;

int n, m, k;
vector<ii> g[N];
int d[N][N];
ii q[N];
ii e[N];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
		e[i] = {u, v};
	}

	// dijkstra
	for (int u = 1; u <= n; u++) {
		for (int v = 1; v <= n; v++)
			d[u][v] = 1e9;

		d[u][u] = 0;
		priority_queue<ii, vector<ii>, greater<ii>> pq;
		pq.push({0, u});
		vector<bool> done(n + 1, false);

		while (!pq.empty()) {
			auto uu = pq.top();
			pq.pop();
			int dis = uu.x;
			int v = uu.y;
			if (done[v])
				continue;
			done[v] = 1;

			for (ii e : g[v]) {
				int nx = e.x;
				if (d[u][nx] > d[u][v] + e.y) {
					d[u][nx] = d[u][v] + e.y;
					pq.push({d[u][nx], nx});
				}
			}
		}
	}

	// for (int i = 1; i <= n; i++){
	// 	for (int j = 1; j <= n; j++)
	// 		cout << d[i][j] << ' ';
	// 	cout << endl;
	// }

	for (int i = 1; i <= k; i++)
		cin >> q[i].x >> q[i].y;

	int ans = 1e9;

	for (int i = 1; i <= m; i++) {
		int sum = 0;
		int x = e[i].x;
		int y = e[i].y;
		for (int j = 1; j <= k; j++) {
			int u = q[j].x;
			int v = q[j].y;
			sum += min({d[u][v], d[u][x] + d[y][v], d[u][y] + d[v][x]});
		}
		ans = min(ans, sum);
	}

	cout << ans << '\n';


	return 0;
}