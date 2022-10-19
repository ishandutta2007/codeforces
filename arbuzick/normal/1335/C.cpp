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
		vector<int> a(n);
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		sort(a.begin(), a.end());
		int r = 0, l = 0, max_l = 0;
		for (int i = 0; i < n; ++i) {
			if (i == 0 || a[i] != a[i - 1]) {
				r += 1;
				l = 1;
			}
			else
				l += 1;
			max_l = max(max_l, l);
		}
		if (r == max_l)
			cout << r - 1 << endl;
		else
			cout << min(max_l, r) << endl;
	}
	return 0;
}