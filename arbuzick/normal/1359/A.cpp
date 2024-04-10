#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		if (m <= n / k)
			cout << m << "\n";
		else {
			int k1 = (m - n / k - 1) / (k - 1) + 1;
			cout << n / k - k1 << "\n";
		}
	}
	return 0;
}