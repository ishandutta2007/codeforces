#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	int n, m;
	cin >> n >> m;
	long double ans = 1;
	for (int i = 1; i <= 2 * n; i++) {
		long double u;
		cin >> u;
		ans *= (1 - 1 / u);
	}
	if (ans == 0) return cout << -1, 0;
	ans = (m - m * ans) / ans;
	if (ans < 0) return cout << -1, 0;
	cout << setprecision(10) << fixed << ans;
	return 0;
}