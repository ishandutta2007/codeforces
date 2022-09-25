#include <bits/stdc++.h>

using namespace std;

const int MX = 100000;

int dp[3 * MX];

int solve(vector<int> d, int R, int n) {
	dp[0] = 0;
	int res = 1;
	for (int i = 1; i <= R; i++) {
		dp[i] = n + 1;
		for (int x : d) if (x <= i) dp[i] = min(dp[i], dp[i - x] + 1);
		if (dp[i] <= n) res++;
	}
	
	return res;
}

int main() {
	int n;
	ignore = scanf("%d", &n);
	
	long long ans;
	if (49ll * n < 3 * MX) ans = solve({0, 4, 9, 49}, 49 * n, n);
	else {
		long long L = MX + 1, R = 49ll * n - MX - 1;
		ans = solve({0, 4, 9, 49}, MX, n);
		ans += solve({40, 45, 49}, MX, n);
		ans += R - L + 1;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}