#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[55][55], b[55][55];
inline bool chk() {
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (a[i][j] != '.' && a[i][j] != b[i][j]) return false;
	return true;
}
inline void Out() {
	puts("YES");
	for (int i = 1; i <= n; i++) {
		b[i][m + 1] = 0;
		puts(b[i] + 1);
	}
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) scanf(" %s", a[i] + 1);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				b[i][j] = ((i + j) & 1) ? 'R' : 'W';
			}
		}
		if (chk()) {
			Out();
			continue;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				b[i][j] = ((i + j) & 1) ? 'W' : 'R';
			}
		}
		if (chk()) {
			Out();
			continue;
		}
		puts("NO");
	}
	return 0;
}