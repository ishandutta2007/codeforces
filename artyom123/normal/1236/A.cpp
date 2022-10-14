#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
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
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		int ans = 0;
		for (int i = 0; i <= 100; i++) {
			for (int j = 0; j <= 100; j++) {
				int cnt1 = i;
				int cnt2 = 2 * i + j;
				int cnt3 = 2 * j;
				if (cnt1 <= a && cnt2 <= b && cnt3 <= c) {
					ans = max(ans, cnt1 + cnt2 + cnt3);
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}