#include <bits/stdc++.h>
using namespace std;
char s[505], t[1005];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf(" %s %s", s + 1, t + 1);
		int n = strlen(s + 1), m = strlen(t + 1), flag = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m && s[i + j - 1] == t[j]; j++) {
				int ok = 1;
				for (int k = j; k <= m; k++) if (s[i + j - 1 - k + j] != t[k]) { ok = 0; break; }
				if (ok) { flag = 1; break; }
			}
			if (flag) break;
		}
		if (!flag) puts("NO");
		else puts("YES");
	}
	return 0;
}