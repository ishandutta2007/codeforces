#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int x, n, m;
		cin >> x >> n >> m;
		while (m > 0) {
			if (x / 2 + 10 < x&&n > 0) {
				x = x / 2 + 10;
				n -= 1;
			}
			else {
				x = x - 10;
				m -= 1;
			}
		}
		if (x <= 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}