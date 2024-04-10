#include <bits/stdc++.h>

using namespace std;

const int M = 3030;

int n, m;
vector<int> g[M];
int q[M], qf, qs;
bool used[M];
int d[M][M];
int s1, t1, s2, t2, l1, l2;
int ans = -1;

void relax(int t) {
	ans = max(ans, t);
}

void read() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	cin >> s1 >> t1 >> l1;
	cin >> s2 >> t2 >> l2;
	--s1, --s2, --t1, --t2;
}

void bfs(int v) {
	fill(used, used + n, false);
	qs = qf = 0;
	q[qf++] = v;
	d[v][v] = 0;
	used[v] = true;

	while (qs < qf) {
		int u = q[qs++];
		for (int to : g[u])
			if (!used[to]) {
				d[v][to] = d[v][u] + 1;
				q[qf++] = to;
				used[to] = true;
			}
	}
}

void kill() {
	for (int i = 0; i < n; ++i)
		bfs(i);

	if (d[s1][t1] <= l1 && d[s2][t2] <= l2) {
		relax(m - d[s1][t1] - d[s2][t2]);
	}

	/*for (int i = 0; i < n; ++i, cout << "\n")
		for (int j = 0; j < n; ++j, cout << " ")
			cerr << d[i][j];*/

	for (int x = 0; x < n; ++x)
		for (int y = 0; y < n; ++y)
			if (d[s1][x] + d[x][y] + d[y][t1] <= l1) {
				if (d[s2][x] + d[x][y] + d[y][t2] <= l2)
					relax(m - d[s1][x] - d[x][y] - d[y][t1] - d[s2][x] - d[y][t2]);
				if (d[s2][y] + d[y][x] + d[x][t2] <= l2)
					relax(m - d[s1][x] - d[x][y] - d[y][t1] - d[s2][y] - d[x][t2]);
			}

	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	read();
	kill();
	return 0;
}