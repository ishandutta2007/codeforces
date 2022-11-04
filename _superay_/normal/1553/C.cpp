#include <bits/stdc++.h>
using namespace std;
char s[15];
inline int cmp(int x, int y) {
	if (x < y) return -1;
	if (x > y) return 1;
	return 0;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf(" %s", s);
		int bf = 0, ans = 10;
		for (int i = 0; i < 10; i++) if (s[i] == '?') bf |= (1 << i);
		for (int mask = 0; mask < (1 << 10); mask++) if ((mask | bf) == bf) {
			for (int i = 0; i < 10; i++) if ((bf >> i & 1)) {
				if (mask >> i & 1) s[i] = '1';
				else s[i] = '0';
			}
			int sc[2];
			sc[0] = sc[1] = 0;
			for (int i = 0; i < 10; i++) {
				if (s[i] == '1') sc[i % 2]++;
				if (cmp(sc[0] + (9 - i) / 2, sc[1]) == cmp(sc[0], sc[1] + (10 - i) / 2)) {
					ans = min(ans, i + 1);
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}