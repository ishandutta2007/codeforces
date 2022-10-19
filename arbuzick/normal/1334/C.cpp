#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int j = 0; j < t; ++j) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; ++i)
			cin >> a[i] >> b[i];
		vector<int> ans(n);
		vector<int> c(n);
		int x = 0;
		int c1 = 0;
		for (int i = 0; i < n; ++i) {
			c[(i + 1) % n] = max(x, a[(i + 1) % n] - b[i]);
			c1 += c[(i + 1) % n];
		}
		int ans1 = -1;
		for (int i = 0; i < n; ++i) {
			ans[i] = c1 + a[i] - c[i];
			if (ans1 == -1)
				ans1 = ans[i];
			ans1 = min(ans1, ans[i]);
		}
		cout << ans1 << endl;
	}
	return 0;
}