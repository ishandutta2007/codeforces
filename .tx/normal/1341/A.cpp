#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	for (int it = 0; it < t; it++) {
		int n, a, b, c, d;
		cin >> n >> a >> b >> c >> d;
		int mn = (a - b) * n;
		int mx = (a + b) * n;
		if (c + d < mn || c - d > mx) {
			cout << "No\n";
		} else {
			cout << "Yes\n";
		}
	}

	return 0;
}