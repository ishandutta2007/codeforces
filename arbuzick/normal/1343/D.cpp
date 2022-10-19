#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int j = 0; j < n; ++j)
			cin >> a[j];
		vector<int> ans(k * 2 - 1);
		for (int j = 0; j < n / 2; ++j) {
			int l1, x, l2;
			l1 = min(a[j], a[n - j - 1]) + 1;
			x = a[j] + a[n - j - 1];
			l2 = max(a[j], a[n - j - 1]) + k;
			ans[0] += 2;
			ans[l1 - 2] -= 1;
			ans[x-2] -= 1;
			if(x-1 < k*2-1)
				ans[x - 1] += 1;
			if (l2 - 1 < k * 2 - 1)
				ans[l2 - 1] += 1;
		}
		int m = n;
		int x = 0;
		for (int j = 0; j < ans.size(); ++j) {
			x += ans[j];
			m = min(m, x);
		}
		cout << m << endl;
	}
	return 0;
}