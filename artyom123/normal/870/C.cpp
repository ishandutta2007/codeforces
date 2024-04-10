#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		if (n == 11) {
			cout << -1 << "\n";
			continue;
		}
		if (n % 2 == 1 && n < 9) {
			cout << -1 << "\n";
			continue;
		}
		if (n % 2 == 0 && n < 4) {
			cout << -1 << "\n";
			continue;
		}
		if (n % 2 == 0) {
			if (n % 4 == 0) {
				cout << n / 4 << "\n";
			} else {
				cout << (n - 6) / 4 + 1 << "\n";
			}
			continue;
		}
		int k = n - 9;
		if (k % 2 == 0) {
			if (k % 4 == 0) {
				cout << k / 4 + 1 << "\n";
			} else {
				cout << (k - 6) / 4 + 2 << "\n";
			}
			continue;
		}
	}
	return 0;
}