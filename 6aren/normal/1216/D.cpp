#include<bits/stdc++.h>
using namespace std;

int n, a[200005];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	int gcd = 0;
	for (int i = 1; i < n; i++) {
		gcd = __gcd(a[n] - a[i], gcd);
	}
	if (gcd == 0) {
		cout << 0 << ' ' << 0;
	} else {
		long long res = 0;
		for (int i = 1; i <= n; i++) {
			res += (a[n] - a[i]) / gcd;
		}
		cout << res << ' ' << gcd;
	}
	return 0;
}