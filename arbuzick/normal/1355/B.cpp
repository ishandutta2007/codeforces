#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> e(n);
		for (int i = 0; i < n; ++i)
			cin >> e[i];
		sort(e.begin(), e.end());
		int ans = 0;
		int k = 0;
		for (int i = 0; i < n; ++i) {
			k += 1;
			if (k >= e[i]) {
				ans += 1;
				k = 0;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}