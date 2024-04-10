#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 2005
int n, k, a[N][N], ans, ss[N][N];
bool pr[N][N], pc[N][N], sr[N][N], sc[N][N];
char s[N];
int main(){
	n = read(), k = read();
	for (register int i = 1; i <= n; ++i){
		scanf("%s", s + 1);
		for (register int j = 1; j <= n; ++j) a[i][j] = s[j] == 'W';
	}
	for (register int i = 1; i <= n; ++i) pr[i][0] = pc[i][0] = 1;
	for (register int i = 1; i <= n; ++i)
		for (register int j = 1; j <= n; ++j)
			pr[i][j] = pr[i][j - 1] && a[i][j], pc[j][i] = pc[j][i - 1] && a[i][j];
	for (register int i = 1; i <= n; ++i) sr[i][n + 1] = sc[i][n + 1] = 1;
	for (register int i = n; i; --i)
		for (register int j = n; j; --j)
			sr[i][j] = sr[i][j + 1] && a[i][j], sc[j][i] = sc[j][i + 1] && a[i][j];
	for (register int i = 1; i <= n; ++i)
		for (register int j = k; j <= n; ++j)
			ss[i][j] = ss[i - 1][j] + (pr[i][j - k] && sr[i][j + 1]);
	for (register int i = k; i <= n; ++i){
		int sum = 0;
		for (register int j = 1; j <= i - k; ++j) sum += pr[j][n];
		for (register int j = i + 1; j <= n; ++j) sum += pr[j][n];
		for (register int j = k + 1; j <= n; ++j) sum += pc[j][n];
		for (register int j = 1; j <= k; ++j) sum += pc[j][i - k] && sc[j][i + 1];
		ans = std :: max(ans, sum + ss[i][k] - ss[i - k][k]);
		for (register int j = k + 1; j <= n; ++j){
			sum = sum - (pc[j - k][i - k] && sc[j - k][i + 1]) + pc[j - k][n];
			sum = sum + (pc[j][i - k] && sc[j][i + 1]) - pc[j][n];
			ans = std :: max(ans, sum + ss[i][j] - ss[i - k][j]);
		}
	}
	printf("%d\n", ans);
}