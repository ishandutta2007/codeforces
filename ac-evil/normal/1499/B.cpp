#include <bits/stdc++.h>
const int N = 105;
int T, n; char s[N];
int main() {
	scanf("%d", &T);
	while (T--) {
		int ok = 1;
		scanf("%s", s + 1); n = strlen(s + 1);
		int t = -1;
		for (int i = 2; i <= n; i++)
			if (s[i] == s[i - 1]) {
				if (s[i] - '0' < t) { ok = 0; break; }
				t = s[i] - '0';
			}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}