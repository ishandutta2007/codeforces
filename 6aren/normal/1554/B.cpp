#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k; 
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) cin >> a[i];
		long long res = -1e18;
		for (int i = max(1, n - 201); i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				res = max(res, 1LL * i * j - k * (a[i] | a[j]));
			}
		}
		cout << res << '\n';
	}

	return 0;
}