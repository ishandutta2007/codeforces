#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool check(int n, int u, int r, int d, int l, int c0, int c1, int c2, int c3) {
	if (c0) {
		l--;
		u--;
	}
	if (c1) {
		u--;
		r--;
	}
	if (c2) {
		r--;
		d--;
	}
	if (c3) {
		d--;
		l--;
	}
	return (min({ u, l, r, d }) >= 0) && (max({ u, l, r, d }) <= n - 2);
}

void solve() {
	int n, u, r, d, l;
	cin >> n >> u >> r >> d >> l;
	for (int c0 = 0; c0 < 2; c0++) {
		for (int c1 = 0; c1 < 2; c1++) {
			for (int c2 = 0; c2 < 2; c2++) {
				for (int c3 = 0; c3 < 2; c3++) {
					if (check(n, u, r, d, l, c0, c1, c2, c3)) {
						cout << "YES\n";
						return;
					}
				}
			}
		}
	}
	cout << "NO\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}