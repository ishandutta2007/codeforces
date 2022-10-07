#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
const int N = 61;
int n, m, sa, sp;
char a[N][N];
void solve(){
	scanf("%d%d", &n, &m), sa = sp = 0;
	for (register int i = 1; i <= n; ++i) scanf("%s", a[i] + 1);
	for (register int i = 1; i <= n; ++i)
		for (register int j = 1; j <= m; ++j)
			sa += a[i][j] == 'A', sp += a[i][j] == 'P';
	if (sa == n * m) return puts("0"), void(0);
	if (sp == n * m) return puts("MORTAL"), void(0);
	sa = 0;
	for (register int i = 1; i <= m; ++i) sa += a[1][i] == 'A';
	if (sa == m) return puts("1"), void(0);
	sa = 0;
	for (register int i = 1; i <= m; ++i) sa += a[n][i] == 'A';
	if (sa == m) return puts("1"), void(0);
	sa = 0;
	for (register int i = 1; i <= n; ++i) sa += a[i][1] == 'A';
	if (sa == n) return puts("1"), void(0);
	sa = 0;
	for (register int i = 1; i <= n; ++i) sa += a[i][m] == 'A';
	if (sa == n) return puts("1"), void(0);
	if (a[1][1] == 'A' || a[1][m] == 'A' || a[n][1] == 'A' || a[n][m] == 'A') return puts("2"), void(0);
	for (register int i = 1; i <= n; ++i){
		sa = 0;
		for (register int j = 1; j <= m; ++j) sa += a[i][j] == 'A';
		if (sa == m) return puts("2"), void(0);
	}
	for (register int j = 1; j <= m; ++j){
		sa = 0;
		for (register int i = 1; i <= n; ++i) sa += a[i][j] == 'A';
		if (sa == n) return puts("2"), void(0);
	}
	sa = 0;
	for (register int i = 1; i <= m; ++i) sa += a[1][i] == 'A';
	if (sa) return puts("3"), void(0);
	sa = 0;
	for (register int i = 1; i <= m; ++i) sa += a[n][i] == 'A';
	if (sa) return puts("3"), void(0);
	sa = 0;
	for (register int i = 1; i <= n; ++i) sa += a[i][1] == 'A';
	if (sa) return puts("3"), void(0);
	sa = 0;
	for (register int i = 1; i <= n; ++i) sa += a[i][m] == 'A';
	if (sa) return puts("3"), void(0);
	puts("4");
}
int main(){
	int T;
	scanf("%d", &T);
	while (T--) solve();
}