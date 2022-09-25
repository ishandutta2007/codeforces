#include <bits/stdc++.h>

using namespace std;

const int MX = 1000000;

int cnt[MX], dp[MX + 1][3][3];

int main() {
	int n, m;
	ignore = scanf("%d %d", &n, &m);
	for (int i = 0, x; i < n; i++) {
		ignore = scanf("%d", &x);
		cnt[x - 1]++;
	}
	
	for (int i = 0; i <= m; i++)
		for (int p = 0; p < 3; p++)
			for (int q = 0; q < 3; q++)
				dp[i][p][q] = -1 * MX;
	
	dp[0][0][0] = 0;
	for (int i = 0; i < m; i++)
		for (int p = 0; p < 3; p++)
			for (int q = 0; q < 3; q++)
				for (int r = 0; r < 3; r++) {
					if (cnt[i] < p + q + r) continue;
					int& val = dp[i + 1][q][r];
					val = max(dp[i][p][q] + r + (cnt[i] - p - q - r) / 3, val);
				}
	
	printf("%d\n", dp[m][0][0]);
	
	return 0;
}