#include <iostream>
#include <vector>
#include <algorithm>
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
		vector<int> a(n), b(n);
		string x;
		cin >> x;
		int c;
		c = 0;
		for (int j = 0; j < n; ++j) {
			if (x[j] == '0') {
				a[j] = 0;
				b[j] = 0;
			}
			if (x[j] == '2') {
				if (c == 0) {
					a[j] = 1;
					b[j] = 1;
				}
				else {
					a[j] = 0;
					b[j] = 2;
				}
			}
			if (x[j] == '1') {
				if (c == 0) {
					a[j] = 1;
					b[j] = 0;
					c = 1;
				}
				else {
					a[j] = 0;
					b[j] = 1;
				}
			}
		}
		for (int j = 0; j < n; ++j)
			cout << a[j];
		cout << endl;
		for (int j = 0; j < n; ++j)
			cout << b[j];
		cout << endl;
	}
	return 0;
}