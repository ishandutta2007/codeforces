#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 593119681

int n, ans = INF, Dp[20][20];
char s[20], t[20];

int Calc(int u, int v)
{
	sprintf(s + 1, "%d", u);
	sprintf(t + 1, "%d", v);
	u = strlen(s + 1);
	v = strlen(t + 1);
	memset(Dp, 0, sizeof(Dp));
	for (int i = 1; i <= u; i ++)
		for (int j = 1; j <= v; j ++)
		{
			if (s[i] == t[j])
				Dp[i][j] = Dp[i - 1][j - 1] + 1;
			else Dp[i][j] = max(Dp[i][j - 1], Dp[i - 1][j]);
		}
	if (Dp[u][v] == u)
		return v - u;
	else return INF;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i * i <= n; i ++)
		ans = min(ans, Calc(i * i, n));
	printf("%d\n", ans == INF ? -1 : ans);
	return 0;
}