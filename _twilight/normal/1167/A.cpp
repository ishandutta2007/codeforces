#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

int T, n;
char s[105];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%s", &n, s);
		int i = 0;
		for ( ; i < n && s[i] != '8'; i++);
		puts((n - i >= 11) ? ("YES") : ("NO"));
	}
	return 0;
}