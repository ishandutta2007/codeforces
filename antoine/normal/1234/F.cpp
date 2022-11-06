#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int dp[1 << 20];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	string s;
	cin >> s;
	for (int i = 0; i < (int) s.size(); ++i) {
		int mask = 0;
		for (int j = i; j < (int) s.size(); ++j) {
			const int x = s[j] - 'a';
			if (mask & (1 << x))
				break;
			mask |= 1 << x;
			dp[mask] = max(dp[mask], j - i + 1);
		}
	}
	for (int mask = 0; mask < (1 << 20); ++mask)
		for (int i = 0; i < 20; ++i)
			dp[mask | (1 << i)] = max(dp[mask | (1 << i)], dp[mask]);

	int ans = 0;
	for (int mask = 0; mask < (1 << 20); ++mask)
		ans = max(ans, dp[mask] + dp[(~mask) & ((1 << 20) - 1)]);
	cout << ans;
	return 0;
}