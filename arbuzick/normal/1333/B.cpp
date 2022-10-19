#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		vector<int> a(n);
		int m = n, p = n;
		for (int j = 0; j < n; ++j) {
			cin >> a[j];
			if (a[j] == -1)
				m = min(m, j);
			if (a[j] == 1)
				p = min(p, j);
		}
		vector<int> b(n);
		for (int j = 0; j < n; ++j)
			cin >> b[j];
		for (int j = 0; j < n; ++j) {
			if (b[j] > a[j] && p >= j) {
				cout << "NO" << endl;
				break;
			}
			if (b[j] < a[j] && m >= j) {
				cout << "NO" << endl;
				break;
			}
			if (j == n - 1)
				cout << "YES" << endl;
		}
	}
	return 0;
}