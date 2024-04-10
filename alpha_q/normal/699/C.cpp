#include <bits/stdc++.h>

using namespace std;

const int N = 110;
const int INF = 1e9;

int n, a[N], dp[N][4];

int call (int pos, int last) {
	if (pos == 0) return 0;
	if (dp[pos][last] != -1) return dp[pos][last];
	
	if (last == 0) {
		return dp[pos][last] = 1 + min(min(call(pos - 1, 0), call(pos - 1, 1)), call(pos - 1, 2));
	}
	if (last == 1) {
		if (a[pos] == 0 or a[pos] == 1) return dp[pos][last] = INF;
		return dp[pos][last] = min(call(pos - 1, 0), call(pos - 1, 2));
	}
	if (last == 2) {
		if (a[pos] == 0 or a[pos] == 2) return dp[pos][last] = INF;
		return dp[pos][last] = min(call(pos - 1, 0), call(pos - 1, 1));
	}
}

int main (int argc, char const *argv[]) {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	memset(dp, -1, sizeof dp);
	
	printf("%d\n", min(call(n, 0), min(call(n, 1), call(n, 2))));
	return 0;
}