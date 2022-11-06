#include <bits/stdc++.h>
const int N = 100005;
int T, n; char s[N];
int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d", &n); scanf("%s", s);
		putchar('1');
		for (int i = 1, las = 1; i < n; i++) {
			int x = s[i] - '0';
			if (x+1 != s[i-1]-'0'+las) las = 1, putchar('1');
			else las = 0, putchar('0');
		}
		puts("");
	}
	return 0;
}