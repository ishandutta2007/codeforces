#include <stdio.h>
#include <string.h>
char s[100002], q[100002], x[28];
int good[26] = { 0 };
int main() {
	int i, N, j, idx = -1, ans, ls, lq;
	scanf("%s", x);
	for (i = 0; i < strlen(x); i++) {
		good[x[i] - 'a'] = 1;
	}
	scanf("%s", s);
	ls = strlen(s);
	for (idx = 0; idx < ls; idx++) {
		if (s[idx] == '*') break;
	}
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		ans = 1;
		scanf("%s", q);
		lq = strlen(q);
		if (idx != ls && lq < ls - 1) ans = 0;
		if (idx == ls && lq != ls) ans = 0;
		for (j = 0; j < idx; j++) {
			if (s[j] == '?') {
				if (good[q[j] - 'a'] == 0) ans = 0;
			}
			else {
				if (s[j] != q[j]) ans = 0;
			}
			if (ans == 0) break;
		}
		if (idx != ls) {
			for (j = 1; j < ls - idx; j++) {
				if (s[ls - j] == '?') {
					if (good[q[lq - j] - 'a'] == 0) ans = 0;
				}
				else {
					if (s[ls - j] != q[lq - j]) ans = 0;
				}
				if (ans == 0) break;
			}
			for (j = idx; j <= lq - ls + idx; j++) {
				if (good[q[j] - 'a'] == 1) ans = 0;
				if (ans == 0) break;
			}
		}
		if (ans == 1) printf("YES\n");
		else printf("NO\n");
	}
}