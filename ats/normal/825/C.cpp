#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int k, n;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] <= 2 * k) {
			k = max(k, a[i]);
		}
		else {
			res--;
			while (a[i] > k) {
				k *= 2;
				res++;
			}
			k = a[i];
		}
	//	cerr << k << endl;
	}
	cout << res << endl;
	return 0;
}