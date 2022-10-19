#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve(int n, int m) {
	int cur = 0;
	int res = 0;
	for (int i = 30; i >= 0; i--) {
		if (cur + (n & (1 << i)) + (1 << i) - 1 <= m) {
			res += (1 << i);
			cur += (1 << i);			
		} else {
			cur += (n & (1 << i));
		}
	}
	return res;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		cout << solve(n, m) << '\n';
	}

	return 0;
}