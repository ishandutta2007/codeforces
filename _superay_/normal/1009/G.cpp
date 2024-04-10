#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, cc[6], ca[64], cs[64], cd[64], allow[N];
char s[N];
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++) cc[s[i] - 'a']++, allow[i] = 63;
	int m;
	scanf("%d", &m);
	while (m--) {
		int i;
		scanf("%d %s", &i, s + 1);
		int len = strlen(s + 1);
		allow[i] = 0;
		for (int j = 1; j <= len; j++) {
			allow[i] |= (1 << (s[j] - 'a'));
		}
	}
	for (int i = 1; i <= n; i++) ca[allow[i]]++;
	for (int i = 1; i <= n; i++) {
		int found = 0;
		ca[allow[i]]--;
		memcpy(cs, ca, sizeof(ca));
		for (int j = 0; j < 6; j++) {
			for (int mask = 0; mask < 64; mask++) if (mask >> j & 1) {
				cs[mask] += cs[mask ^ (1 << j)];
			}
		}
		for (int c = 0; c < 6; c++) if (cc[c] && (allow[i] >> c & 1)) {
			cc[c]--;
			int good = 1;
			for (int j = 0; j < 6; j++) cd[1 << j] = cc[j];
			for (int mask = 0; mask < 64; mask++) {
				if (mask) cd[mask] = cd[mask & (mask - 1)] + cd[mask ^ (mask & (mask - 1))];
				if (cd[mask] > n - i - cs[63 ^ mask]) {
					good = 0;
					break;
				}
			}
			if (good) {
				s[i] = 'a' + c;
				found = 1;
				break;
			}
			cc[c]++;
		}
		if (!found) {
			puts("Impossible");
			return 0;
		}
	}
	s[n + 1] = 0;
	puts(s + 1);
	return 0;
}