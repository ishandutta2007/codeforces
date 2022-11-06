#include <bits/stdc++.h>
int T;
char s[105];
int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%s", s);
		printf("%d\n", strlen(s));
	}
	return 0;
}