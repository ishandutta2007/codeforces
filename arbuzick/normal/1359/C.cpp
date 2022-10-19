#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		double h, c, t;
		cin >> h >> c >> t;
		if (t == h) {
			cout << "1\n";
			continue;
		}
		if (t <= (h + c) / 2) {
			cout << "2\n";
			continue;
		}
		int l = 0, r = 1e9;
		while (l < r - 1) {
			int m = (l + r) / 2;
			double t1 = ((h + c) * m + h) / (m * 2 + 1);
			if (t1 >= t)
				l = m;
			else
				r = m;
		}
		double t1 = ((h + c) * l + h) / (l * 2 + 1), t2 = ((h + c) * r + h) / (r * 2 + 1);
		if (abs(t - t1) <= abs(t - t2))
			cout << l * 2 + 1 << "\n";
		else
			cout << r * 2 + 1 << "\n";
	}
	return 0;
}