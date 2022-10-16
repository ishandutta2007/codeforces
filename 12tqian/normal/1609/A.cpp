#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	int n;
	cin >> n;
	vector<int> a(n);
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		while (a[i] % 2 == 0) {
			a[i] >>= 1;
			++cnt;
		}
	}
	long long mx = *max_element(a.begin(), a.end());
	long long ans = accumulate(a.begin(), a.end(), 0) - mx + (mx << cnt);
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