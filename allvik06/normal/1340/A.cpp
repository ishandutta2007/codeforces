#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n), z(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i]; --a[i];
			z[a[i]] = i;
		}
		int now = 0;
		int len = n;
		bool res = true;
		while (len > 0) {
			int i = 0;
			i = z[now];
			bool flag = true;
			for (int j = i + 1; j < len; ++j) {
				if (a[j] - a[j - 1] != 1) {
					flag = false;
					break;
				}
			}
			if (!flag) {
				res = false;
				break;
			}
			len = i;
			now = n - i;
		}
		if (res) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}