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
		int ans = 1000;
		int k = 0, f = 0;
		for (int i = 0; i < n; ++i) {
			k += a[i] % 2;
			if (i > 0)
				if (a[i] - a[i - 1] == 1)
					f = 1;
		}
		if (k % 2 == 0 || f)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}