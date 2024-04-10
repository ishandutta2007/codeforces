#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	int t;
	cin >> t;
	while (t--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int ans = (y2 - y1) * (y2 - y1);
		ans += ((x2 - x1) - (y2 - y1))*(y2-y1);
		ans++;
		cout << ans << "\n";
	}
	return 0;
}