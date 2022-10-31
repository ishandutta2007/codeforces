#include "bits/stdc++.h"
using namespace std;

int main() {
	int n; int k;
	while (~scanf("%d%d", &n, &k)) {
		vector<long long> as(n);
		for (int i = 0; i < n; ++ i)
			scanf("%lld", &as[i]);
		long long ans = 0, mask = 0;
		for (int bi = 60; bi >= 0; -- bi) {
			mask |= 1LL << bi;
			vector<vector<bool>> dp(n + 1, vector<bool>(k + 1));
			dp[0][0] = true;
			for (int i = 0; i < n; ++ i) for (int j = 0; j < k; ++ j) if(dp[i][j]) {
				long long sum = 0;
				for (int l = i + 1; l <= n; ++ l) {
					sum += as[l - 1];
					if ((sum & mask) == mask)
						dp[l][j + 1] = true;
				}
			}
			if (dp[n][k])
				ans |= 1LL << bi;
			else
				mask &= ~(1LL << bi);
		}
		printf("%lld\n", ans);
	}
}