#include <bits/stdc++.h>
using namespace std;
char s[100005];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf(" %s", s + 1);
		int n = strlen(s + 1);
		int fnd = 0;
		for (int i = 1; i <= n; i++) if (s[i] == '0') fnd = 1;
		if (!fnd) puts("0");
		else {
			int mn = 1e9, mx = 0, c = 0;
			for (int i = 1; i <= n; i++) if (s[i] == '0') {
				mn = min(mn, i);
				mx = max(mx, i);
				c++;
			}
			if (mx - mn + 1 == c) puts("1");
			else puts("2");
		}
	}
	return 0;
}