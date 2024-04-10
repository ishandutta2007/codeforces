#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	cin >> tt;

	while (tt--) {
		int n;
		cin >> n;
		if (n <= 26) {
			for (int i = 0; i < n; i++) {
				cout << (char) ('a' + i);
			}
			cout << '\n';
			continue;
		}
		int u = (n - 3) / 2;
		for (int i = 0; i < u; i++) {
			cout << 'z';
		}
		int rem = n - 2 * u - 1;
		for (int i = 0; i < rem; i++) {
			cout << (char) ('a' + i);
		}
		for (int i = 0; i <= u; i++) {
			cout << 'z';
		}
		cout << '\n';
	}

	return 0;
}