#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	int n, l;
	cin >> n >> l;
	vector<int> x(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	int ans = 0;
	for (int i = 0; i < l; ++i) {
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			if (x[j] & (1 << i)) {
				++cnt;
			}
		}
		if (cnt > n / 2) {
			ans += (1 << i);
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}