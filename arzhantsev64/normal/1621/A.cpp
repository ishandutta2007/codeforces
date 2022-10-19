#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pt pair<int, int>
#define x first
#define y second

void solve() {
	int n, k;
	cin >> n >> k;
	if (n < 2 * k - 1) {
		cout << -1 << endl;
		return;
	}
	string s0 = string(n, '.');
	for (int i = 0; i < n; ++i) {
		string s = s0;
		if (i % 2 == 0 && (i / 2) + 1 <= k)
			s[i] = 'R';
		cout << s << '\n';
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