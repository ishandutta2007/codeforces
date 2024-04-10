#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

int solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	bool sorted = true;
	for (int i = 0; i < n - 1; ++i)
		sorted &= (a[i] < a[i + 1]);
	if (sorted)
		return 0;

	if (a[0] == 1 || a[n - 1] == n)
		return 1;

	if (a[0] == n && a[n - 1] == 1)
		return 3;

	return 2;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		cout << solve() << '\n';
	
	return 0;
}