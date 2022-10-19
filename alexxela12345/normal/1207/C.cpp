#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e15;

signed main() {
	int t;
	cin >> t;
	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;
		string s;
		cin >> s;
		vector<vector<int>> dp(n, vector<int> (2, INF));
		dp[0][0] = a + 2 * b;
		dp[0][1] = 2 * a + 3 * b;
		for (int i = 1; i < n; i++) {
			if (s[i] == '0') {
				dp[i][0] = min(dp[i - 1][0] + a + b, dp[i - 1][1] + 2 * a + b);
				dp[i][1] = min(dp[i - 1][0] + 2 * a + 2 * b, dp[i - 1][1] + a + 2 * b);
			} else {
				dp[i][0] = INF;
				dp[i][1] = dp[i - 1][1] + a + 2 * b;
			}
		}
		cout << dp.back()[0] << endl;
	}
}