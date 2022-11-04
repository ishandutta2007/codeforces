#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, m, pw[1000005];
int main() {
	cin >> n >> m;
	int ans = 0;
	for (int i = pw[0] = 1; i <= n; i++) {
		pw[i] = 1ll * pw[i - 1] * m % mod;
	}
	for (int i = n, p = 1; i >= 0; i--) {
		ans = (ans + 1ll * pw[i] * p) % mod;
		if (i < n) p = 1ll * p * (2 * m - 1) % mod;
		else p = m;
	}
	cout << ans << endl;
	return 0;
}