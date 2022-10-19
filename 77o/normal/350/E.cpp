#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 305;

int g[N][N];
int dp1[N][N], dp2[N][N];

int main() {
	// freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(k);
	vector<int> used(n + 1);
	for (int i = 0; i < k; i++) {
		cin >> a[i];
		// a[i] = i + 2;
		used[a[i]] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			g[i][j] = (i == j ? 0 : 1e9);
		}
	}
	if (k == n) {
		cout << "-1\n";
		return 0;
	}
	sort(a.begin(), a.end());
	int x = a[0];
	int y = a[1];
	int z = 1;
	for (; used[z]; z++);
	vector<pair<int, int>> edges;
	edges.emplace_back(x, z);
	edges.emplace_back(y, z);
	g[x][z] = g[z][x] = 1;
	g[y][z] = g[z][y] = 1;
	m -= 2;
	for (int i = 1; i <= n && m; i++) {
		for (int j = i + 1; j <= n && m; j++) {
			if (g[i][j] != 1e9) {
				continue;
			}
			if (used[i] && j == y || used[j] && i == y) {
				continue;
			}
			m--;
			edges.emplace_back(i, j);
		}
	}
	if (m) {
		cout << "-1\n";
		return 0;
	}
	for (auto p : edges) {
		cout << p.first << ' ' << p.second << '\n';
	}
	return 0;
}