#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	int n; 
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	long long ans = 0;
	if (n == 1) {
		ans = a[0];
		cout << ans << '\n';
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			if (a[i] > a[i + 1]) {
				ans += a[i] - a[i + 1];
				a[i] = a[i + 1];
			}
			ans += a[i];
		} else if (i == n - 1) {
			if (a[i] > a[i - 1]) {
				ans += a[i] - a[i - 1];
				a[i] = a[i - 1];
			} 
			ans += a[i];
		} else {
			int bef = a[i];
			a[i] = min(a[i], max(a[i + 1], a[i - 1]));
			ans += bef - a[i];
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		ans += abs(a[i] - a[i + 1]);
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