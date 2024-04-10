#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, a, b;
		cin >> n >> m >> a >> b;
		if (a * n != m * b) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		string s;
		for (int i = 0; i < m; ++i) {
			if (i < a)
				s += '1';
			else
				s += '0';
		}
		int x = max(n, m), y = min(n, m);
		while (y != 0) {
			x %= y;
			int z = x;
			x = y;
			y = z;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = i * (n*m/x/n); j < i * (n * m / x / n) + m; ++j)
				cout << s[j % m];
			cout << "\n";
		}
	}
	return 0;
}