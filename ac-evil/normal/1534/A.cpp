#include <bits/stdc++.h>
const int N = 1e3 + 5;
int T, n, m; char a[N][N];
char getc() {
	char c;
	while (c = getchar(), c != '.' && c != 'R' && c != 'W');
	return c;
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		int op = -1;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				a[i][j] = getc();
				if (op == -1 && a[i][j] != '.') op = (i + j + (a[i][j] == 'R')) & 1;
			}
		if (op == -1) op = 0;
		int ok = 1;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				char tag = (i + j + op) & 1 ? 'R' : 'W';
				if (a[i][j] == '.') a[i][j] = tag;
				else if (a[i][j] != tag) { ok = 0; goto lab; }
			}
		lab:
		if (!ok) { puts("NO"); continue; }
		puts("YES");
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				printf("%c", a[i][j]);
			puts("");
		}
	}
}