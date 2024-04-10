#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pt pair<int, int>
#define x first
#define y second

void solve() {
	int n;
	cin >> n;
	int l0 = 1e18;
	int cost_l = 0;
	int r0 = -1e18;
	int cost_r = 0;
	int len = -1e18;
	int cost_len = 0;

	for (int i = 0; i < n; ++i) {
		int l, r, c;
		cin >> l >> r >> c;

		if (l == l0)
			cost_l = min(c, cost_l);
		if (l < l0) {
			l0 = l;
			cost_l = c;
		}

		if (r == r0)
			cost_r = min(c, cost_r);
		if (r > r0) {
			r0 = r;
			cost_r = c;
		}

		if (r - l == len)
			cost_len = min(c, cost_len);
		if (r - l > len) {
			len = r - l;
			cost_len = c;
		}

		// cout << l0 << ' ' << cost_l << endl;
		// cout << r0 << ' ' << cost_r << endl;
		// cout << len << ' ' << cost_len << endl;

		if (r0 - l0 == len)
			cout << min(cost_len, cost_l + cost_r) << '\n';
		else if (r0 - l0 > len)
			cout << cost_l + cost_r << '\n';
		else
			cout << cost_len << '\n';
	}

}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}