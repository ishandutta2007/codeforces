#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<char> c(n);
		for (int i = 0; i < n; ++i)
			c[i] = s[i];
		sort(c.begin(), c.end());
		if (c[0] != c[k - 1]) {
			cout << c[k - 1] << "\n";
		}
		else {
			string ans = "";
			ans += c[k - 1];
			if (c[k] == c[n - 1]) {
				for (int i = k; i < k + (n - k - 1) / k + 1; ++i)
					ans += c[i];
			}
			else {
				for (int i = k; i < n; ++i)
					ans += c[i];
			}
			cout << ans << "\n";
		}
	}
	return 0;
}