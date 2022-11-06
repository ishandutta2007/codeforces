#include <bits/stdc++.h>
const int N = 100005;
int T, n;
char s[N], t[2*N];
int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%s", s); n = strlen(s);
		int ans = 0;
		for (int i = 1; i < n; i++) {
			if (s[i-1] != ' ' && s[i] == s[i-1] || (i > 1 && s[i] == s[i-2] && s[i-2] != ' ')) ans++, s[i] = ' ';
		}
		printf("%d\n", ans);
	}
	return 0;
}