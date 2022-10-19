#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		sort(a.begin(), a.end());
		int ans = 1;
		for (int i = 0; i < n; ++i) {
			if (a[i] <= i + 1)
				ans = i + 2;
		}
		cout << ans << "\n";
	}
	return 0;
}