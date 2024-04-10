#include <bits/stdc++.h> 

using namespace std;

const int N = 105;

long long n, m, k, x, y, g[N][N];

int main (int argc, char const *argv[]) {
	cin >> n >> m >> k >> x >> y;
	if (n == 1) {
		long long q = k/m, r = k % m;
		for (int i = 1; i <= m; ++i) {
			g[1][i] = q;
		}
		for (int i = 1; i <= r; ++i) {
			++g[1][i];
		}
		long long mini = g[1][1], maxi = g[1][1];
		for (int i = 1; i <= m; ++i) {
			mini = min(mini, g[1][i]);
			maxi = max(maxi, g[1][i]);
		}
		printf("%lld %lld %lld\n", maxi, mini, g[x][y]);
		return 0;
	}
	long long z = 2LL * (n - 1LL) * m;
	long long q = k/z, r = k % z;
	for (int i = 1; i <= m; ++i) {
		g[1][i] = g[n][i] = q;
	}
	for (int i = 2; i < n; ++i) {
		for (int j = 1; j <= m; ++j) {
			g[i][j] = q + q;
		}
	}
	for (int i = 1; i <= n and r; ++i) {
		for (int j = 1; j <= m and r; ++j) {
			++g[i][j], --r;
		}
	}
	for (int i = n - 1; i >= 2 and r; --i) {
		for (int j = 1; j <= m and r; ++j) {
			++g[i][j], --r;
		}
	}
	long long mini = g[1][1], maxi = g[1][1];
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			mini = min(mini, g[i][j]);
			maxi = max(maxi, g[i][j]);
		}
	}
	printf("%lld %lld %lld\n", maxi, mini, g[x][y]);
	return 0;
}