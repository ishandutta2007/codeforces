#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int Mx = 5002;

int a[Mx + 9];
int dp[Mx + 2][Mx + 2][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	// 0, n + 1

	for (int diff = n + 1; diff >= 0; --diff) {
		for (int i = 0; i <= n + 1; ++i) {
			const int j = i + diff;
			for (int k = 0; k < 2; ++k) {
				int &res = dp[i][j][k] = 1 << 30;

				if (i < 1 && k == 1)
					res = j >= n ? 0 : (a[j] != a[j + 1]) + dp[i][j + 1][k];
				if (j > n && k == 0)
					res = i <= 1 ? 0 : (a[i] != a[i - 1]) + dp[i - 1][j][k];

				if (i < 1 || j > n)
					continue;

				if (i == 1 && j == n) {
					res = a[i] != a[j];
					continue;
				}

				if (a[i] == a[j]) {
					res = dp[i - 1][j][1];
					continue;
				}

				if (a[i] == a[i - 1]) {
					res = dp[i - 1][j][k];
					continue;
				}
				if (a[j] == a[j + 1]) {
					res = dp[i][j + 1][k];
					continue;
				}

				if (k == 0)
					res = 1 + min(dp[i - 1][j][0], dp[i - 1][j][1]);
				else
					res = 1 + min(dp[i][j + 1][0], dp[i][j + 1][1]);
			}
			// assert(min(dp[i][j][0], dp[i][j][1]) < (1 << 30));
		}
	}

	int ans = 1 << 30;
	for (int i = 1; i <= n; ++i) {
		assert(dp[i][i][0] == dp[i][i][1]);
		ans = min(ans, dp[i][i][0]);
		// cerr << dp[i][i][0] << endl;
	}
	cout << ans;

	return 0;
}