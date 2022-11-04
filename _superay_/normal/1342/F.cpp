#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n, a[20], sum[1 << 15], dp[20][1 << 15][20], vis[20];
pair<int, int> fr[20][1 << 15][20];
inline void chk(int i, int j, int k, int val, int frj, int frk) {
	if (dp[i][j][k] > val) {
		dp[i][j][k] = val;
		fr[i][j][k] = make_pair(frj, frk);
	}
}
inline int getid(int p) {
	int c = 0;
	for (int i = 0; i <= p; i++) c += vis[i];
	return c;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		sum[0] = 0;
		for (int i = 0; i < n; i++) scanf("%d", &a[i]), sum[1 << i] = a[i];
		for (int i = 0; i < (1 << n); i++) sum[i] = sum[i & (i - 1)] + sum[i ^ (i & (i - 1))];
		for (int i = 0; i <= n; i++) for (int j = 0; j < (1 << n); j++) for (int k = 0; k <= n; k++) dp[i][j][k] = INF;
		dp[0][0][0] = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < (1 << n); j++) {
				for (int k = 0; k <= n; k++) if (dp[i][j][k] < INF) {
					for (int S = ((1 << n) - 1) ^ j, l = S; l; l = (l - 1) & S) {
						if (l >= (1 << k) && dp[i][j][k] < sum[l]) {
							chk(i + 1, j | l, __builtin_ctz(l & ~((1 << k) - 1)) + 1, sum[l], j, k);
						}
					}
				}
			}
		}
		int fnd = 0;
		for (int i = 0; i < n; i++) vis[i] = 1;
		for (int i = n; ; i--) {
			for (int k = 0; k <= n; k++) if (dp[i][(1 << n) - 1][k] < INF) {
				printf("%d\n", n - i);
				int j = (1 << n) - 1;
				while (i) {
					int lj, lk;
					tie(lj, lk) = fr[i][j][k];
					int cur = j ^ lj;
					while (cur) {
						int pos = __builtin_ctz(cur);
						if (pos != k - 1) printf("%d %d\n", getid(pos), getid(k - 1)), vis[pos] = 0;
						cur ^= (1 << pos);
					}
					j = lj, k = lk;
					i--;
				}
				fnd = 1;
				break;
			}
			if (fnd) break;
		}
	}
	return 0;
}