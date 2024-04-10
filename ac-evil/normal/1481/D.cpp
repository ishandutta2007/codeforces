#include <bits/stdc++.h>
#define pb push_back
using std::max; using std::min; using std::vector;
const int N = 1005;
int T, n, m, e[N][N];
char s[N];
bool check1() {
	for (int i = 1; i <= n; i++)
		for (int j = i+1; j <= n; j++)
			if (e[i][j] == e[j][i]) {
				puts("YES");
				for (int k = 1; k <= m + 1; k++)
					printf("%d ", k & 1 ? i : j);
				puts("");
				return true;
			}
	return false;
}
bool check2() {
	if (n == 2 && m % 2 == 0) return false;
	puts("YES");
	if (m % 2 != 0) {
		for (int i = 1; i <= (m + 1) / 2; i++) printf("1 2 ");
		puts("");
	} else {
		if (e[1][2] == e[2][3] && e[2][3] == e[3][1]) {
			for (int i = 0; i < m + 1; i++) printf("%d ", i % 3 + 1);
			puts("");
		} else {
			int t, u, v;
			if (e[1][2] == e[2][3]) t = 1, u = 2, v = 3;
			else if (e[3][1] == e[1][2]) t = 3, u = 1, v = 2;
			else if (e[2][3] == e[3][1]) t = 2, u = 3, v = 1;
			if ((m/2) % 2 == 0) {
				printf("%d ", u);
				for (int i = 1; i <= m/2; i++) printf("%d ", i & 1 ? v : u);
				for (int i = 1; i <= m/2; i++) printf("%d ", i & 1 ? t : u);
				puts("");
			} else {
				printf("%d ", t);
				for (int i = 1; i <= m/2; i++) printf("%d ", i & 1 ? u : t);
				for (int i = 1; i <= m/2; i++) printf("%d ", i & 1 ? v : u);
				puts("");
			}
		}
	}
	return true;
}
int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%s", s);
			for (int j = 1; j <= n; j++)
				if (s[j-1] == 'a') e[i][j] = 1;
				else if (s[j-1] == 'b') e[i][j] = 2;
		}
		if (check1()) continue;
		if (check2()) continue;
		puts("NO");
	}
	return 0;
}