#include<bits/stdc++.h>
using namespace std;

const int N = 105;

int n;
char s[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		scanf("%s", s + 1);
		for (int i = 1; i <= n; i++)
			if (s[i] == 'L' || s[i] == 'R') putchar(s[i]);
			else if (s[i] == 'U') putchar('D');
			else putchar('U');
		puts("");
	}
	return 0;
}