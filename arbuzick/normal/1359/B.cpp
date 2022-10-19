#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, m, x, y;
		cin >> n >> m >> x >> y;
		vector<string> s(n);
		for (int i = 0; i < n; ++i)
			cin >> s[i];
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			int j = 0;
			while (j < m) {
				if (s[i][j] == '.') {
					if (x * 2 > y&& j + 1 < m && s[i][j + 1] == '.') {
						ans += y;
						j += 2;
					}
					else {
						ans += x;
						j += 1;
					}
				}
				else {
					j += 1;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}