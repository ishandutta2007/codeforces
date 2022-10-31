#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int c = 0;
	int r = 0;
	int t;
	int res = -1;
	for (int i = 0; i < n; i++) {
		c += a[i];
		t = min((int)8, c);
		r += t;
		c -= t;
		if (r >= k && (res==-1)) {
			res = i + 1;
		}
	}
	cout << res << endl;
	return 0;
}