#include <bits/stdc++.h>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, x, y = 0;
		cin >> n >> x;
		bool b = false;
		for (int j = 1; j <= n; j++) {
			int z;
			cin >> z;
			y = max(y, z);
			if (z == x) {
				b = true;
			}
		}
		int ans = (int) ceil((double) x / y);
		if (!b) {
			ans = max(ans, 2);
		}
		cout << ans << endl;
	}
	return 0;
}