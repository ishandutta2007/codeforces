#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pt pair<int, int>
#define x first
#define y second

int cnt_zeros(int n, int d) {
	n++;
	int k = 1 << d;
	return (n / k) * (k / 2) + min(k / 2, n % k);
}

void solve() {
	int l, r;
	cin >> l >> r;
	int ans = r - l;
	for (int i = 1; i <= 20; ++i) {
		ans = min(ans, cnt_zeros(r, i) - cnt_zeros(l - 1, i));
	}
	cout << ans << '\n';
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