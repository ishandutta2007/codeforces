#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, m;
		cin >> n >> m;
		int m2 = n - m;
		int ans = (n + 1) * n / 2;
		if (m2 % (m + 1) == 0)
			ans = ans - ((m2 / (m + 1) + 1) * (m2 / (m + 1)) / 2) * (m + 1);
		else {
			int a1 = m2 % (m + 1), a2 = m + 1 - a1;
			ans = ans - ((m2 / (m + 1) + 2) * (m2 / (m + 1) + 1) / 2) * a1 - ((m2 / (m + 1) + 1) * (m2 / (m + 1)) / 2) * a2;
		}
		cout << ans << endl;
	}
	return 0;
}