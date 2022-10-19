#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int ans = 0;
	for (int z = c; z <= d; ++z) {
		int min_x = max(a, z - c + 1);
		if (min_x <= b) {
			int min_y = max(z - min_x + 1, b);
			int k1 = c - min_y + 1, k2 = b - min_x + 1;
			int ans1;
			if (k2 - 1 > c - b + 1 - k1) {
				ans1 = (k1 + c - b + 1) * (c - b + 1 - k1 + 1) / 2;
				ans1 += (k2 - 1 - (c - b + 1 - k1)) * (c - b + 1);
			}
			else {
				ans1 = (k1 + k1 + k2 - 1) * k2 / 2;
			}
			ans += ans1;
		}
	}
	cout << ans;
	return 0;
}