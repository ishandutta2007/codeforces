#include <iostream>
#include <algorithm>
using namespace std;

const int N = 4005, T = 86400;

pair <int, int> a[2 * N];
int dp[N][N];
int dp2[N][N];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a + 1, a + n + 1);
	for (int i = n + 1; i <= 2 * n + 1; i++) {
		a[i] = {T + 1, T + 1};
	}
//	a[n + 1] = {T, T};
	int ans = 0;
	for (int j = 0; j <= k; j++) {
		dp[0][j] = 1;
	}
	for (int i = 1; i <= n; i++) {
		dp[i][0] = max(dp[i - 1][0], a[i].first) + a[i].second;
		dp2[i][0] = dp2[i - 1][0];
		if (a[i].first > dp[i - 1][0]) {
			dp2[i][0] += a[i].first - dp[i - 1][0] - 1;
		}
	//	cout << i << " " << 0 << " " << dp[i][0] << " " << dp2[i][0] << endl;
		for (int j = 1; j <= k; j++) {
			dp[i][j] = max(dp[i - 1][j], a[i].first) + a[i].second;
			dp2[i][j] = dp2[i - 1][j];
			if (a[i].first > dp[i - 1][j]) {
				dp2[i][j] += a[i].first - dp[i - 1][j] - 1;
			}
			if (dp[i - 1][j - 1] < dp[i][j]) {
				dp[i][j] = dp[i - 1][j - 1];
				dp2[i][j] = dp2[i - 1][j - 1];
			}
		//	dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
		//	dp2[i][j] = max(dp2[i][j], dp2[i - 1][j - 1]);
		//	cout << i << " " << j << " " << dp[i][j] << " " << dp2[i][j] << endl;
		}
	}
	for (int i = 0 ; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			ans = max(ans, a[i + 1 + k - j].first - dp[i][j]);
		}
	}
	cout << ans;
	return 0;
}