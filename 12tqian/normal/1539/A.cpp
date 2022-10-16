#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	long long n, x, t;
	cin >> n >> x >> t;
	long long ans = 0;
	long long amt = t / x;
	if (amt >= n - 1) {
		ans = n * (n - 1) / 2;
	} else {
		ans = amt * (amt + 1) / 2;
		ans += amt * (n - amt - 1);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1; 
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}