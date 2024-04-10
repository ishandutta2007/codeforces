#include <bits/stdc++.h>
typedef long long LL;
const int M = 100005;
int n, m, ok[M];
int main() {
	scanf("%d%d", &n, &m);
	memset(ok, -1, sizeof ok);
	ok[0] = 0;
	for (int time = 1; time <= n; time++) {
		int op, y; LL _x; scanf("%d%lld%d", &op, &_x, &y);
		if (op == 1) {
			int x = (_x + 99999) / 100000;
			for (int i = m; ~i; i--)
				if (~ok[i]) {
					int o = i;
					for (int j = 1; j <= y; j++) {
						o += x;
						if (o > m || ~ok[o]) break;
						ok[o] = time;
					}
				}
		} else {
			LL x = _x;
			for (int i = m; ~i; i--)
				if (~ok[i]) {
					int o = i;
					for (int j = 1; j <= y; j++) {
						if (x * o > m * 100000LL) break;
						o = (o * x + 99999) / 100000;
						if (~ok[o]) break;
						ok[o] = time;
					}
				}
		}
	}
	for (int i = 1; i <= m; i++) printf("%d ", ok[i]);
	return 0;
}