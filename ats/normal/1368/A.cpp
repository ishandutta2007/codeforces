#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		int a, b, n;
		cin >> a >> b >> n;
		int res = 0;
		while (true) {
			if (a > b) swap(a, b);
			if (b > n) break;
			a += b;
			res++;
		}
		cout << res << "\n";
	}
	return 0;
}