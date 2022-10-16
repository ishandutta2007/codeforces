#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		a[i] = s[i] - '0';
		b[i] = t[i] - '0';
	}
	if (a == b) {
		cout << 0 << '\n';
	} else {
		int sa = accumulate(a.begin(), a.end(), 0);
		int sb = accumulate(b.begin(), b.end(), 0);
		int da = n - 2 * sa;
		int db = n - 2 * sb;
		if (sa != sb && n - sa + 1 != sb) {
			cout << -1 << '\n';
		} else {
			int ans = 5 * n;
			if (n - sa + 1 == sb) {
				int res = 0;
				for (int i = 0; i < n; ++i) {
					res += a[i] ^ b[i] ^ 1; 
				}
				ans = min(ans, res);
			} 
			if (sa == sb) {
				int res = 0;
				for (int i = 0; i < n; ++i) {
					res += a[i] ^ b[i];
				}
				ans = min(ans, res);
			}
			cout << ans << '\n';
		}
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