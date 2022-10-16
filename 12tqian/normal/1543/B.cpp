#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	int n;
	cin >> n;
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		sum += x;
	}
	sum %= n;
	long long ans = sum * (n - sum);
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