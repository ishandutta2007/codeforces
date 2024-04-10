#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
	int c, d;
	cin >> c >> d;
	if (abs(c - d) % 2 != 0) {
		cout << -1 << "\n";
	} else if (c == 0 && d == 0) {
		cout << 0 << "\n";
	} else if (c == d) {
		cout << 1 << "\n";
	} else {
		cout << 2 << "\n";
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}