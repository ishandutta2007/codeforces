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
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	// d - (n - d) >= k
	// 2d >= n + k
	int d = (n + k + 1) / 2;
	vector<int> b = a;
	sort(b.begin(), b.end());	
	int min_d = 1e18;
	int x = -1;
	int y = -1;
	for (int i = 0; i + d <= b.size(); ++i) {
		if (b[i + d - 1] - b[i] < min_d) {
			min_d = b[i + d - 1] - b[i];
			x = b[i];
			y = b[i + d - 1];
		}
	}
	cout << x << ' ' << y << '\n';
	int bal = 0;
	int need = 1;
	if (need == k && 2 * d - n > k)
		need++;
	int have = 0;
	int last = -1;
	for (int i = 0; i < n; ++i) {
		if (have == k - 1)
			break;
		bal += (x <= a[i] && a[i] <= y) * 2 - 1;
		if (bal == need) {
			cout << last + 2 << ' ' << i + 1 << '\n';
			last = i;
			need++;
			have++;
			if (need == k && 2 * d - n > k)
				need++;
		}
	}
	cout << last + 2 << ' ' << n << '\n';
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