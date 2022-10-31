#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		int x = N / 14;
		x = max((int)1, x - 5);
		string res = "NO";
		for (int j = x; j <= x + 10; j++) {
			int t = j * 21 - 7 * (j - 1);
			if (N >= t - 6 && N <= t - 1) {
				res = "YES";
			}
		}
		cout << res << "\n";
	}
	return 0;
}