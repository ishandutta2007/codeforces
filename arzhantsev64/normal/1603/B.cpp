#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
	int x, y;
	cin >> x >> y;
	if (x > y)
		cout << (x + y) << "\n";
	else if (y - x == 2)
		cout << (x + y) / 2 << "\n";
	else if (y % x == 0)
		cout << x << "\n";
	else {
		int d = y % x;
		int r = d / 2;
		y -= d;
		int k = y / x;
		cout << k * x + r << "\n";

	}
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