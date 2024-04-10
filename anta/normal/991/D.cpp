#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }
int main() {
	array<string, 2> rows;
	while (cin >> rows[0] >> rows[1]) {
		int n = (int)rows[0].size();
		vector<vector<int>> dp(n + 1, vector<int>(1 << 2, -1));
		dp[0][0] = 0;
		for (int i = 0; i < n; ++ i) {
			int t = (rows[0][i] != '0' ? 1 : 0) | (rows[1][i] != '0' ? 2 : 0);
			for (int j = 0; j < 1 << 2; ++ j) {
				if ((j & t) != 0) continue;
				int x = dp[i][j];
				if (x == -1) continue;
				int u = j | t;
				amax(dp[i + 1][0], x);
				if ((u & 3) == 0) amax(dp[i + 1][1], x + 1);
				if ((u & 1) == 0) amax(dp[i + 1][3], x + 1);
				if ((u & 2) == 0) amax(dp[i + 1][3], x + 1);
				if ((u & 3) == 0) amax(dp[i + 1][2], x + 1);
			}
		}
		int ans = dp[n][0];
		printf("%d\n", ans);
	}
}