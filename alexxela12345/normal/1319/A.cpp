#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(20);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] + b[i] == 1) {
			if (a[i] == 1) {
				cnt1++;
			} else {
				cnt2++;
			}
		}
	}
	if (cnt1 == 0) {
		cout << -1 << endl;
		return 0;
	};
	cout << (cnt2 + 1 + cnt1 - 1) / cnt1 << endl;
	return 0;
}