#include <bits/stdc++.h>

using namespace std;

int n, m, k, a[200005];

long long ans = 0;

int32_t main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	long long t = 1LL * k * a[n - 1] + a[n - 2];
	ans = 1LL * m / (k + 1) * t + 1LL * (m % (k + 1)) * a[n - 1];
	cout << ans;
	return 0;
}