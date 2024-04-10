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
	string a, b;
	cin >> a >> b;
	int have_0 = 0;
	int have_1 = 0;
	int other_0 = 0;
	int other_1 = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] != b[i]) {
			if (a[i] == '0')
				have_0++;
			else
				have_1++;
		} else {
			if (a[i] == '0')
				other_0++;
			else
				other_1++;

		}
	}
	// cout << have_0 << '\n';
	// cout << have_1 << '\n';
	// cout << other_0 << '\n';
	// cout << other_1 << '\n';
	int ans = 1e18;
	if ((have_0 + have_1) % 2 == 0 && ((have_0 == have_1) || (have_0 == have_1 - 1))) {
		ans = min(ans, have_0 + have_1);
	}
	if ((other_0 + other_1) % 2 == 1 && ((other_0 == other_1) || (other_0 == other_1 - 1))) {
		ans = min(ans, other_0 + other_1);
	}
	// cout << "ANS\n";
	cout << (ans == 1e18 ? -1 : ans) << '\n';

}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}