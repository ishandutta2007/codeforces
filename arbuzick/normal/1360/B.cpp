#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> s(n);
		for (int i = 0; i < n; ++i)
			cin >> s[i];
		sort(s.begin(), s.end());
		int ans = 1000;
		for (int i = 1; i < n; ++i)
			ans = min(ans, s[i] - s[i - 1]);
		cout << ans << "\n";
	}
	return 0;
}