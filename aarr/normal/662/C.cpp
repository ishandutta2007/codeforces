#include <iostream>
using namespace std;

const int N = 20, M = 100 * 1000 + 5;

int dp[(1 << N)][N + 1][2];
int a[M];


int get(int x, int y) {
	return (x >> y) & 1;
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			a[j] += (1 << i) * (c - '0');
		}
	}
	for (int j = 0; j < m; j++) {
		dp[a[j]][0][0]++;
	}
//	for (int mask = 0; mask < 1 << n; mask++) {
//		cout << mask << " " << dp[mask][0][0] << endl;
//	}
	for (int j = 1; j <= n; j++) {
		for (int mask = 0; mask < (1 << n); mask++) {
			for (int i = 0; i <= n; i++) {
				dp[mask][i][j % 2] = dp[mask][i][1 - j % 2];
				if (i > 0) {
					dp[mask][i][j % 2] += dp[mask ^ (1 << (j - 1))][i - 1][1 - j % 2];
				}
			}	
		}
	}
	int ans = n * m;
	for (int mask = 0; mask < 1 << n; mask++) {
		int x = 0;
		for (int i = 0; i <= n; i++) {
			x += dp[mask][i][n % 2] * min(i, n - i);
		}
		ans = min(ans, x);
	}
	cout << ans << endl;
	return 0;
}