#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, ta, tb, k;
	cin >> n >> m >> ta >> tb >> k;
	int a[n], b[m];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int j = 0; j < m; j++) {
		cin >> b[j];
	}
	int ans = 0;
	for(int i = 0; i <= min(k, n); i++) {
		if(i == n) {
			cout << -1 << endl;
			return 0;
		} else {
			auto it = lower_bound(b, b + m, a[i] + ta);
			if(b + m - it <= k - i) {
				cout << -1 << endl;
				return 0;
			} else {
				ans = max(ans, *(it + k - i) + tb);
			}
		}
	}
	cout << ans << endl;
	return 0;
}