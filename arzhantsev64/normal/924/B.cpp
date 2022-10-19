#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef long double ld;

void solve() {
	int n, U;
	cin >> n >> U;
	vector< ld > E(n);
	for (ld& ee : E) {
		int x;
		cin >> x;
		ee = x;
	}
	int k = 2;
	ld ans = 0;
	for (int i = 0; i + 2 < n; ++i) {
		k = max(k, i + 2);
		for (; k != n - 1 && E[k + 1] - E[i] <= U; ++k);
		if (E[k] - E[i] > U) continue;
		ans = max(ans, (E[k] - E[i + 1]) / (E[k] - E[i]));
	}
	if (ans == 0) {
		cout << -1 << endl;
	} else {
		cout << fixed << ans << endl;
	}
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);
    solve();
	return 0;
}