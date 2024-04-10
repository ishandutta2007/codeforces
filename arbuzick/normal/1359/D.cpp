#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int ans = 0;
	for (int i = 1; i < 31; ++i) {
		int s = 0;
		int m = 0;
		for (int j = 0; j < n; ++j) {
			if (a[j] > i)
				s -= 31;
			else
				s += a[j];
			m = min(m, s);
			ans = max(ans, (s - m) - i);
		}
	}
	cout << ans;
	return 0;
}