#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	for (int it = 0; it < t; it++) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int& i : a) {
			cin >> i;
		}
		vector<int> b(n);
		for (int i = 1; i + 1 < n; i++) {
			if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
				b[i] = 1;
			}
		}

		int aa = -1;
		int al, ar;
		int c = 0;
		for (int i = 0; i < n; i++) {
			if (i >= k - 1) {
				c -= b[i - k + 1];
				if (c > aa) {
					aa = c;
					al = i - k + 1;
					ar = i;
				}
			}
			c += b[i];
		}
		cout << aa + 1 << " " << al + 1 << "\n";
	}

	return 0;
}