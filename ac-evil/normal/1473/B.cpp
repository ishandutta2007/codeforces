#include <bits/stdc++.h>
const int N = 25;
int T;
char s[N*N], t[N*N];
int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%s%s", s, t);
		int ok = 1, i = 0, n = strlen(s), m = strlen(t);
		while (i <= 1000) {
			if (s[i%n] != t[i%m]) { ok = 0; break; }
			if (i && i%n == 0 && i%m == 0) break;
			i++;
		}
		if (!ok || i > 1000) puts("-1");
		else {
			for (int j = 0; j < i / n; j++) printf("%s", s);
			puts("");
		}
	}
	return 0;
}