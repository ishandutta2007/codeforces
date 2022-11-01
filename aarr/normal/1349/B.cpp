#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 5;

int a[N];

int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int n, k;
		cin >> n >> k;
		bool b = false, c = false;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i] == k) {
				b = true;
			}
			if (i > 1 && a[i] >= k && a[i - 1] >= k) {
				c = true;
			}
			if (i > 2 && a[i] >= k && a[i - 2] >= k) {
				c = true;
			}
		}
		if (n == 1 && a[1] == k) {
			cout << "yes\n";
			continue;
		}
		if (b && c) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}
	
	return 0;
}