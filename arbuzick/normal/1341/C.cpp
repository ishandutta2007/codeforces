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
		vector<int> p(n);
		for (int j = 0; j < n; ++j)
			cin >> p[j];
		if (n == 1)
			cout << "YES" << endl;
		for (int j = 0; j < n - 1; ++j) {
			if (p[j] < p[j + 1] && p[j] + 1 < p[j + 1]) {
				cout << "NO" << endl;
				break;
			}
			if (j == n - 2)
				cout << "YES" << endl;
		}
	}
	return 0;
}