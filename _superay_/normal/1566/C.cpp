#include <bits/stdc++.h>
using namespace std;
char s[100005], t[100005];
int dp[100005];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		scanf(" %s %s", s + 1, t + 1);
		dp[0] = 0;
		int last[2] = {0, 0};
		for (int i = 1; i <= n; i++) {
			dp[i] = -1;
			last[s[i] - '0'] = i;
			last[t[i] - '0'] = i;
			if (last[0] && last[1]) dp[i] = max(dp[i], dp[min(last[0], last[1]) - 1] + 2);
			if (last[0] && last[1] < last[0]) dp[i] = max(dp[i], dp[last[0] - 1] + 1);
			if (last[1] && last[0] < last[1]) dp[i] = max(dp[i], dp[last[1] - 1] + 0);
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}