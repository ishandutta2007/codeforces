#include <bits/stdc++.h>
using namespace std;


const int N = 200 * 1000 + 5;
int n, m, k;

bool b[N];
vector <int> adj[N];
queue <int> q;
int d1[N];
int d2[N];
vector <pair <int, int> > vec;

void bfs(int s, int d[]) {
	fill(d, d + n + 1, N);
	d[s] = 0;
	q.push(s);
	while (q.size()) {
		int v = q.front();
		q.pop();
		for (auto u : adj[v]) {
			if (d[u] == N) {
				d[u] = d[v] + 1;
				q.push(u);
			}
		}
	}
}
int main() {
	ios :: sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) {
		int x;
		cin >> x;
		b[x] = true;
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bfs(1, d1);
	bfs(n, d2);
	for (int i = 1; i <= n; i++) {
		if (b[i]) {
			vec.push_back({d2[i] - d1[i], d1[i]});
		}
	}
	sort(vec.begin(), vec.end());
	int maxi = -n, ans = d1[n], mx = 0;
	for (auto p : vec) {
		int z = p.first, x = p.second;
		int y = x + z;
	//	cout << "73 " << x << " " << y << endl;
		mx = max(mx, maxi + x + 1);
		maxi = max(maxi, y);
	}
	cout << min(ans, mx);
	return 0;
}