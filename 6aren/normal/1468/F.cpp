#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int ntest;
	cin >> ntest;

	while (ntest--) {
		int n;
		cin >> n;
		map<pair<int, int>, int> cnt;

		for (int i = 0; i < n; i++) {
			int x, y, u, v;
			cin >> x >> y >> u >> v;
			x -= u;
			y -= v;
			int gcd = __gcd(abs(x), abs(y));
			x /= gcd;
			y /= gcd;
			cnt[make_pair(x, y)]++;
		}

		long long ans = 0;

		for (auto foo : cnt) {
			int count = foo.second;
			int x = foo.first.first;
			int y = foo.first.second;
			ans += 1LL * count * cnt[make_pair(-x, -y)];
		}

		assert(ans % 2 == 0);

		cout << ans /2 << '\n';

	}

	return 0;
}