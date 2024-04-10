#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
	int n;
	cin >> n;
	vector<int> odd;
	vector<int> even;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (x % 2 == 0)
			even.push_back(i);
		else
			odd.push_back(i);
	}
	int ans = 1e18 + 7;
	if (odd.size() == (n + 1) / 2) {
		int a = 0;
		for (int i = 0; i < odd.size(); ++i)
			a += abs(2 * i - odd[i]);
		ans = min(ans, a);
	}
	if (even.size() == (n + 1) / 2) {
		int a = 0;
		for (int i = 0; i < even.size(); ++i)
			a += abs(2 * i - even[i]);
		ans = min(ans, a);
	}
	cout << (ans == 1e18 + 7 ? -1 : ans) << endl;
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