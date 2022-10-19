#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

#define int long long
#define bit(x, y) ((x >> y) & 1)

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int ntest;
	cin >> ntest;

	while (ntest--) {
		int n;
		cin >> n;
		vector<int> x(n);
		vector<int> cnt(60, 0);
		for (int &e : x) {
			cin >> e;
			for (int i = 59; i >= 0; i--) {
				if (bit(e, i)) {
					cnt[i]++;
				}
			}
		}

		// for (int i = 0; i < 60; i++) 
		// 	cout << cnt[i] << ' ';
		// cout << '\n';

		long long ans = 0;

		for (int e : x) {
			int sumL = 0;
			int sumR = 0;
			for (int i = 0; i < 60; i++) {
				if (bit(e, i) == 1) {
					sumL += ((1LL << i) % MOD) * cnt[i] % MOD;
					sumR += ((1LL << i) % MOD) * n % MOD;
				} else {
					sumR += ((1LL << i) % MOD) * cnt[i] % MOD;
					// cout << sumR << ' ' << cnt[i] << '\n';
				}
				sumL %= MOD;
				sumR %= MOD;
			}

			ans = (ans + 1LL * sumL * sumR % MOD) % MOD;
		}

		cout << ans << '\n';
	}

	return 0;
}