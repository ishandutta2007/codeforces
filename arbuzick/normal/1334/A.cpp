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
		vector<int> p(n), c(n);
		for (int i = 0; i < n; ++i)
			cin >> p[i] >> c[i];
		if (n == 1 && c[0] <= p[0])
			cout << "YES" << endl;
		else if (n == 1)
			cout << "NO" << endl;
		for (int i = 1; i < n; ++i) {
			if (c[0] > p[0]) {
				cout << "NO" << endl;
				break;
			}
			if (c[i - 1] > c[i] || p[i - 1] > p[i]) {
				cout << "NO" << endl;
				break;
			}
			if (p[i] - p[i - 1] < c[i] - c[i - 1]||c[i] > p[i]) {
				cout << "NO" << endl;
				break;
			}
			if (i == n - 1)
				cout << "YES" << endl;
		}
	}
	return 0;
}