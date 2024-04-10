#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int a, k;
		cin >> a >> k;
		if (k == 1) {
			cout << a << "\n";
			continue;
		}
		int pr = a - 1;
		int i = 1;
		while (a != pr) {
			i += 1;
			pr = a;
			int m1 = 9, m2 = 0;
			while (a != 0) {
				m1 = min(m1, a % 10);
				m2 = max(m2, a % 10);
				a /= 10;
			}
			a = pr + m1 * m2;
			if (i == k) {
				cout << a << "\n";
				break;
			}
		}
		if (i != k)
			cout << a << "\n";
	}
	return 0;
}