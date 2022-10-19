#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		int k = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			k += a[i] % 2;
		}
		if (k == 0) {
			cout << "NO\n";
			continue;
		}
		if (x == n && k % 2 == 0||(k == n&&x%2 == 0))
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}