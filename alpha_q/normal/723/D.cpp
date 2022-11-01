#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 10;

int n, m, k, cur = 0, comp = 0;
char g[55][55];
int vis[55][55], vis2[55][55];
vector < pair <int, int> > lens;

bool valid (int x, int y) {
	return x >= 1 and y >= 1 and x <= n and y <= m and g[x][y] == '.';
}

void dfs (int x, int y) {
	if (!valid(x, y)) return;
	if (vis[x][y]) return;

	vis[x][y] = comp, ++cur;
	if (x == 1 or x == n or y == 1 or y == m) cur = -INF;
	dfs(x + 1, y), dfs(x, y + 1), dfs(x - 1, y), dfs(x, y - 1);
}

void dfs2 (int x, int y) {
	if (!valid(x, y)) return;
	if (vis2[x][y]) return;

	vis2[x][y] = 1, g[x][y] = '*';
	dfs(x + 1, y), dfs(x, y + 1), dfs(x - 1, y), dfs(x, y - 1);
}

int main (int argc, char const *argv[]) {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j)
			cin >> g[i][j];

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (g[i][j] == '.' and !vis[i][j]) {
				cur = 0, ++comp, dfs(i, j);
				if (cur > 0) lens.push_back(make_pair(cur, comp));
			}

	sort(lens.begin(), lens.end());
	int pos = 0, tot = 0, now = (int) lens.size();

	while (now > k) {
		tot += lens[pos].first;
		int id = lens[pos].second;
		now--, pos++;

		for (int i = 1; i <= n; ++i) 
			for (int j = 1; j <= m; ++j) {
				if (vis[i][j] == id) dfs2(i, j);
			}
	}

	printf("%d\n", tot);
	for (int i = 1; i <= n; ++i) printf("%s\n", g[i] + 1);
	return 0; 
}