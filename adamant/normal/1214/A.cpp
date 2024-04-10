#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

signed main() {
	int n, d, e;
	cin >> n >> d >> e;
	int ans = n;
	for(int i = 0; i * e <= n; i += 5) {
		ans = min(ans, (n - i * e) % d);
	}
	cout << ans << endl;
    return 0;
}