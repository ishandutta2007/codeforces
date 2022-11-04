#include <bits/stdc++.h>
using namespace std;
double Dp[1010][1010], tmp;
int S[1010], x, y, n, m;
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &S[i]);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) Dp[i][j] = (S[i] > S[j]);
	while(m--) {
		scanf("%d%d", &x, &y);
		for(int i = 1; i <= n; i++) if(i != x && i != y) tmp = Dp[i][x] + Dp[i][y], Dp[i][x] = Dp[i][y] = tmp / 2, Dp[x][i] = Dp[y][i] = 1 - tmp / 2;
		Dp[x][y] = Dp[y][x] = 0.5;
	}
	double ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++) ans += Dp[i][j];
	printf("%.12lf\n", ans);
	return 0;
}