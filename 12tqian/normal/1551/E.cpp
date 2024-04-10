#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	const int INF = 1e9;
	int tt;
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		vector<int> dp(n + 1);
		int ans = INF;
		for (int i = 0; i <= n; ++i) {
			if (dp[i] >= k) {
				ans = min(ans, i - a[i]); 
			}
			for (int j = i + 1; j <= n; ++j) {
				if (a[i] < a[j] && j - a[j] >= max(i - a[i], 0)) {
					dp[j] = max(dp[j], dp[i] + 1);
				}
			}
		}
		if (ans == INF) {
			ans = -1;
		}
		cout << ans << '\n';
	}
	return 0;
}