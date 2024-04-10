#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int j = 0; j < t; ++j) {
		int n, x;
		cin >> n >> x;
		vector<double> a(n);
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
		vector<double> pr(n+1);
		pr[0] = 0;
		for (int i = 0; i < n; ++i) {
			pr[i + 1] = pr[i] + a[i];
		}
		int l = 0, r = n + 1;
		while (l < r-1) {
			int m = (l + r) / 2;
			double s = pr[m] / m;
			if (s < x)
				r = m;
			else
				l = m;
		}
		cout << l << endl;
	}
	return 0;
}