#include <bits/stdc++.h>
 
using namespace std;
 
#define pb emplace_back
#define int long long
#define fi first
#define se second
#define all(x) x.begin(), x.end()

signed main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector <int> a(n);
		vector <int> f(n + 5, -1), l(n + 5);
		for (auto &c : a) {
			cin >> c;
		}
		for (int i = 0; i < n; i++) {
			l[a[i]] = i;
			if (f[a[i]] == -1) {
				f[a[i]] = i;
			}
		}
		vector <int> b = a;
		sort(all(b));
		b.resize(unique(b.begin(), b.end()) - b.begin());
		vector <int> dp(b.size());
		int ans = 0;
		for (int i = 0; i < b.size(); i++) {
			dp[i] = 1;
			if (i > 0 && l[b[i - 1]] < f[b[i]]) {
				dp[i] = 1 + dp[i - 1];
			} 
			ans = max(ans, dp[i]);
		}
		cout << b.size() - ans << "\n";
	}
	return 0;
}