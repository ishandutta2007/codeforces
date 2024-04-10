#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;


int main() {
	ios :: sync_with_stdio(false);
	int n, k, prv = 0;
	cin >> n >> k;
	long long ans1 = 0, ans2 = 1;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x >= n - k + 1 && prv != 0) {
			ans1 += x;
			ans2 *= 1ll * (i - prv);
			ans2 %= mod;
			prv = i;
		}
		else if (x >= n - k + 1) {
			ans1 += x;
			prv = i;
		}
	}
	cout << ans1 << " " << ans2;
	return 0;
}