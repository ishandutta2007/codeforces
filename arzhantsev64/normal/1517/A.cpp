#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int x;
		cin >> x;
		if (x % 2050 != 0) {
			cout << -1 << '\n';
			continue;
		}

		int d = x / 2050;
		int ans = 0;
		while (d != 0) {
			ans += d % 10;
			d /= 10;
		}
		cout << ans << '\n';
	}
	
	return 0;
}