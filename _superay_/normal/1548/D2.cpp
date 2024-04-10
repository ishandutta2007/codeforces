#include <bits/stdc++.h>
using namespace std;
int n, X[6005], Y[6005], cnt[6005][4][4][4];
inline int gb(int x1, int y1, int x2, int y2) {
	return __gcd(abs(x1 - x2), abs(y1 - y2)) % 4;
}
inline int ar(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
	return abs(x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3) % 4;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &X[i], &Y[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int b = gb(X[i], Y[i], X[j], Y[j]);
			cnt[i][X[j] % 4][Y[j] % 4][b]++;
			cnt[j][X[i] % 4][Y[i] % 4][b]++;
		}
	}
	long long eee = 0, ooe = 0;
	for (int i = 1; i <= n; i++) {
		for (int s1 = 0; s1 < 16; s1++) {
			for (int b1 = 0; b1 < 4; b1++) {
				for (int s2 = s1; s2 < 16; s2++) {
					for (int b2 = (s1 == s2 ? b1 : 0); b2 < 4; b2++) if (b1 % 2 == b2 % 2) {
						int x1 = s1 / 4, y1 = s1 % 4;
						int x2 = s2 / 4, y2 = s2 % 4;
						if (x1 % 2 != x2 % 2 || y1 % 2 != y2 % 2) continue;
						int ways;
						int b = (b1 + b2) % 4;
						if (x1 == x2 && y1 == y2) {
							if (b1 == b2) ways = cnt[i][x1][y1][b1] * (cnt[i][x1][y1][b1] - 1) / 2;
							else ways = cnt[i][x1][y1][b1] * cnt[i][x2][y2][b2];
						} else {
							b = (b + 2) % 4;
							ways = cnt[i][x1][y1][b1] * cnt[i][x2][y2][b2];
						}
						if (ar(X[i], Y[i], x1, y1, x2, y2) == b) {
							if (b1 % 2 == 0) eee += ways;
							else ooe += ways;
						}
					}
				}
			}
		}
	}
	printf("%lld\n", eee / 3 + ooe);
	return 0;
}