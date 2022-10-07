#include <cstdio>
#include <cstring>
#define N 200005
int n, a[N], dp[N];
char s[N];
int main(){
	scanf("%s", s + 1), n = strlen(s + 1);
	for (register int i = 1; i <= n; ++i) a[i] = s[i] == 'b', a[n + i] = a[i];
	n <<= 1, dp[1] = 1;
	for (register int i = 2; i <= n; ++i)
		if (a[i] != a[i - 1]) dp[i] = dp[i - 1] + 1; else dp[i] = 1;
	int ans = 1;
	for (register int i = 1; i <= n; ++i) dp[i] > ans ? ans = dp[i] : 0;
	if (ans > n / 2) ans = n / 2;
	printf("%d", ans);
}