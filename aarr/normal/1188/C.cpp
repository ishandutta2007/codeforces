#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1005, M = 100 * 1000 + 5, mod = 998244353;

int dp[N][N];
int a[N];


int main() {
	int n, k, ans = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a[0] = -M;
	sort(a + 1, a + n + 1);
	for (int q = 1; q * (k - 1) < M; q++) {
	//	fill(dp[0], dp[0] + N * N, 0);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++) {
				dp[i][j] = 0;
			}
		}
		int x = 0;
		for (int i = 1; i <= n; i++) {
			dp[i][1] = 1;
			while (a[i] - a[x] >= q) {
				x++;
			}
			for (int j = 1; j <= k; j++) {
				dp[i][j] += dp[i - 1][j];
				dp[i][j] += dp[x - 1][j - 1];
				dp[i][j] %= mod;
			}
		}
		ans += dp[n][k];
		ans %= mod;
	}
	cout << ans;
	return 0;
}