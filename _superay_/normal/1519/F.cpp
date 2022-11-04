#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
inline void getmin(int &x, int y) { if (x > y) x = y; }
int n, m, a[6], b[6], c[6][6], pw[7];
int dp[15625], g[5][15625];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = pw[0] = 1; i <= m; i++) pw[i] = pw[i - 1] * 5;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int j = 0; j < m; j++) scanf("%d", &b[j]);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &c[i][j]);
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		memset(g, 0x3f, sizeof(g));
		memcpy(g[0], dp, sizeof(dp));
		for (int j = 0; j < m; j++) {
			for (int k = a[i] - 1; k >= 0; k--) {
				for (int st = 0; st < pw[m]; st++) if (g[k][st] < INF) {
					for (int cur = 1; k + cur <= a[i] && (st / pw[j]) % 5 + cur <= b[j]; cur++) {
						getmin(g[k + cur][st + cur * pw[j]], g[k][st] + c[i][j]);
					}
				}
			}
		}
		for (int st = 0; st < pw[m]; st++) dp[st] = g[a[i]][st];
	}
	int ans = INF;
	for (int st = 0; st < pw[m]; st++) getmin(ans, dp[st]);
	if (ans == INF) ans = -1;
	printf("%d\n", ans);
	return 0;
}