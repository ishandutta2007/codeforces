#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int ans = n;
		for (int i = 1; i * i <= n; ++i) {
			if (n % i == 0) {
				int j = n / i;
				if (j <= k)
					ans = min(ans, i);
				if (i <= k)
					ans = min(ans, j);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}