#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		for (int j = 0; j < n; ++j)
			cin >> a[j];
		vector<int> v(205);
		for (int j = 0; j < 205; ++j)
			v[j] = 0;
		for (int j = 0; j < n; ++j)
			v[a[j] - 1] = 1;
		int x1 = x;
		for (int j = 0; j < 205; ++j) {
			if (v[j] == 0) {
				if (x1 > 0) {
					v[j] = 1;
					x1 -= 1;
				}
				else {
					cout << j << endl;
					break;
				}
			}
		}
	}
	return 0;
}