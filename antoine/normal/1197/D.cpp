#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;
	vector<ll> a(n + 1, 0);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	partial_sum(a.begin(), a.end(), a.begin());

	const ll Inf = (ll) 1e18;
	vector<ll> dp(m, Inf);
	ll ans = 0;
	for (int i = 0; i <= n; ++i) {
		dp[0] = min(dp[0], a[i]);
		ans = max(ans, a[i] - *min_element(dp.begin(), dp.end()));
		dp[0] += k;
		dp.insert(dp.begin(), dp.back());
		dp.pop_back();
	}

	cout << ans;

	return 0;
}