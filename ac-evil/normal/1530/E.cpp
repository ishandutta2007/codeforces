#include <bits/stdc++.h>
const int N = 1e5 + 5;
int T, n, c[26]; char str[N];
bool check0() {
	for (int i = 0; i < 26; i++)
		if (c[i] == 1) return 1;
	return 0;
}
bool checkn() {
	int cnt = 0;
	for (int i = 0; i < 26; i++)
		if (c[i]) cnt++;
	return cnt == 1;
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%s", str + 1); n = strlen(str + 1);
		std::fill(c, c + 26, 0);
		for (int i = 1; i <= n; i++) c[str[i] - 'a']++;
		int fi = -1, se = -1;
		for (int i = 0; i < 26; i++) {
			if (c[i]) {
				if (fi == -1) fi = i;
				else if (se == -1) se = i;
				else break;
			}
		}
		// ans = 0, 1, n
		if (check0()) {
			for (int i = 0; i < 26; i++)
				if (c[i] == 1) { putchar('a' + i); c[i] = 0; break; }
			for (int i = 0; i < 26; i++)
				for (int j = 1; j <= c[i]; j++)
					putchar('a' + i);
		}
		else if (checkn()) {
			for (int i = 0; i < 26; i++)
				for (int j = 1; j <= c[i]; j++)
					putchar('a' + i);
		}
		else {
			int sum = 0;
			for (int i = fi + 1; i < 26; i++) sum += c[i];
			if (c[fi] <= sum + 2) {
				putchar('a' + fi), putchar('a' + fi), putchar('a' + se);
				c[fi] -= 2, c[se] -= 1;
				while (c[fi]) {
					putchar('a' + fi), putchar('a' + se);
					c[fi]--, c[se]--;
					if (!c[se]) {
						while (se < 26 && !c[se]) se++;
						if (se == 26) break;
					}
				}
				for (int i = 0; i < 26; i++)
					for (int j = 1; j <= c[i]; j++)
						putchar('a' + i);
			} else {
				putchar('a' + fi); c[fi]--;
				int ok = 0;
				for (int i = se + 1; i < 26; i++)
					if (c[i]) { ok = i; break; }
				if (ok) {
					putchar('a' + se); c[se]--;
					for (int i = 1; i <= c[fi]; i++) putchar('a' + fi);
					c[fi] = 0;
					putchar('a' + ok); c[ok]--;
					for (int i = 0; i < 26; i++)
						for (int j = 1; j <= c[i]; j++)
							putchar('a' + i);
				} else {
					for (int i = 1; i <= c[se]; i++) putchar('a' + se);
					c[se] = 0;
					for (int i = 0; i < 26; i++)
						for (int j = 1; j <= c[i]; j++)
							putchar('a' + i);
				}
			}
		}
		puts("");
	}
	return 0;
}