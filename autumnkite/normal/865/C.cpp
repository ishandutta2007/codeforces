#include <cstdio>
#include <algorithm>
int n, m, a[55], b[55], p[55];
double dp[55][10005];
bool check(double x){
	for (register int i = n; i; --i){
		for (register int j = m + 1; j <= 10000; ++j) dp[i + 1][j] = x;
		for (register int j = 0; j <= m; ++j)
			dp[i][j] = std :: min(x, (dp[i + 1][j + a[i]] + a[i]) * p[i] / 100 + (dp[i + 1][j + b[i]] + b[i]) * (100 - p[i]) / 100);
	}
	return dp[1][0] < x;
}
int main(){
	scanf("%d%d", &n, &m);
	for (register int i = 1; i <= n; ++i) scanf("%d%d%d", a + i, b + i, p + i);
	double l = 0, r = 1e9, mid;
	for (register int i = 1; i <= 100; ++i)
		if (check(mid = (l + r) / 2)) r = mid; else l = mid;
	printf("%.12lf", r);
}