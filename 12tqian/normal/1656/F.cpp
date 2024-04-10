#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	long long sum = accumulate(a.begin(), a.end(), 0ll);
	sort(a.begin(), a.end());
	if (1ll * a.back() * (n - 2) + sum < 0 || 1ll * a[0] * (n - 2) + sum > 0) {
		cout << "INF" << '\n';
	} else {
		long long s = 1ll * a.back() * (n - 2) + sum;
		long long v = 1ll * -(n - 1) * a.back() * a.back();

		long long ans = v;
		for (int i = 1; i < n; ++i) {
			long long d = a[n - i] - a[n - i - 1];
			v += s * d;
			ans = max(ans, v);
			s += a[0] - a.back();
		}
		cout << ans << '\n';
	}
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