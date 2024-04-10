#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<ll> a(n + 2, 0);
	cin >> a[n + 1];
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	vector<ll> dp(n + 2, 0);
	for (int i = n; i >= 0; --i)
		dp[i] = a[n + 1] - a[i] - dp[i + 1];

	ll sum = 0, ans = dp[0];
	DBG(dp[1])
	DBG(dp[0])
	for (int i = 0; i <= n; ++i) {
		if (i & 1)
			sum += a[i] - a[i - 1];
		if (a[i + 1] - a[i] < 2)
			continue;

		if (i &1)
				ans = max(ans, sum + dp[i] - 1);
		else
				ans = max(ans, sum + a[i + 1] - a[i] - 1 + dp[i + 1]);


	}
	cout << ans;
	return 0;
}