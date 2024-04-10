#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, c;
	cin >> n >> c;
	vector<int> check(c + 1);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		check[x] = 1;
	}
	vector<int> pref = check;
	for (int i = 1; i <= c; i++) {
		pref[i] += pref[i - 1];
	}
	bool ok = 1;
	for (int i = 1; i <= c; i++) {
		if (!check[i]) continue;
		for (int l = i; l <= c; l += i) {
			int r = min(c, l + i - 1);
			int cnt = pref[r] - (l == 0 ? 0 : pref[l - 1]);
			if (cnt > 0 && !check[l / i]) {
				ok = false;
				break;
			}
		}
	}
	cout << (ok ? "Yes\n" : "No\n");
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
}