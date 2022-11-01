#include <bits/stdc++.h> 

using namespace std;

const int N = 1005;
const int MOD = 1e9 + 7;

char s[N];
int n, a[30], from[N], maxi = 1;
long long dp[N];

long long call (int p) {
	if (p > n) return 1;
	if (dp[p] != -1) return dp[p];
	int len = n, cmax = 1;
	dp[p] = 0;
	for (int q = p, l = 1; ; ++q, ++l) {
		int c = s[q] - 'a' + 1;
		len = min(len, a[c]);
		if (l > len) break;
		cmax = max(cmax, l);
		dp[p] += call(q + 1), dp[p] %= MOD;
	}
	from[p] = cmax;
	maxi = max(maxi, cmax);
	return dp[p];
}

int main (int argc, char const *argv[]) {
	scanf("%d %s", &n, s + 1);
	for (int i = 1; i <= 26; ++i) {
		scanf("%d", a + i);
	}
	memset(dp, -1, sizeof dp);
	for (int i = 1; i <= n; ++i) call(i);
	printf("%lld\n", call(1));
	printf("%d\n", maxi);
	int mini = 0;
	for (int i = 1; i <= n; i += from[i]) {
		++mini;
	}
	printf("%d\n", mini);
    return 0;
}