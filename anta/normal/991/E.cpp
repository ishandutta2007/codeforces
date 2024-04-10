#include "bits/stdc++.h"
using namespace std;
int main() {
	long long n;
	while (~scanf("%lld", &n)) {
		array<int, 10> cnt = {};
		for (auto x = n; x > 0; x /= 10) {
			++ cnt[x % 10];
		}
		long long C[20][20] = {};
		for (int i = 0; i <= 19; i ++) {
			C[i][0] = 1;
			for (int j = 1; j <= i; j ++)
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
		array<int, 10> cur = {};
		function<long long(int)> rec = [&](int d) {
			if (d == 10) {
				long long x = 1;
				int t = 0;
				for (int i = 0; i < 10; ++ i) {
					t += cur[i];
					x *= C[t][cur[i]];
				}
				return x;
			} else {
				long long x = 0;
				for (int i = cnt[d] == 0 ? 0 : 1; i <= cnt[d]; ++ i) {
					cur[d] = i;
					x += rec(d + 1);
					cur[d] = 0;
				}
				return x;
			}
		};
		long long ans = 0;
		ans += rec(0);
		if (cnt[0] != 0) {
			for (int i = 0; i <= cnt[0] - 1; ++ i) {
				cur[0] = i;
				ans -= rec(1);
				cur[0] = 0;
			}
		}
		printf("%lld\n", ans);
	}
}