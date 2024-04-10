#include <bits/stdc++.h>
using namespace std;

const int M = 10, N = 300 * 1000 + 5, inf = 1000 * 1000 * 1000 + 7;

int dp[1 << M];
int mf[1 << M];
int a[N][M];

int get(int x, int y) {
	return (x >> y) & 1;
}
int main() {
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int mask = 0; mask < (1 << m); mask++) {
		dp[mask] = 0;
		for (int i = 0; i < n; i++) {
			int x = inf;
			for (int j = 0; j < m; j++) {
				if (get(mask, j)) {
					x = min(x, a[i][j]);
				}
			}
			if (x > dp[mask]) {
				mf[mask] = i;
				dp[mask] = x;
			}
		}
	//	cout << mask << " " << dp[mask] << " " << mf[mask] << endl;
	}
	pair <int, int> p = {0, 0};
	int ans = 0;
	for (int mask = 0; mask < (1 << m); mask++) {
		int mask2 = mask ^ ((1 << m) - 1);
	//	cout << "73 " << mask << " " << mask2 << " " << min(dp[mask], dp[mask2]) << " " << mf[mask] << " " << mf[mask2] << endl;
		if (min(dp[mask], dp[mask2]) > ans) {
			ans = min(dp[mask], dp[mask2]);
			p = {mf[mask], mf[mask2]};
		}
	}
	cout << p.first + 1 << " " << p.second + 1 << endl;
	return 0;
}