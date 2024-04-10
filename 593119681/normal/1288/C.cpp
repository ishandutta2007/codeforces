#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1000 + 5
#define M 10 + 5
#define Mod 1000000007

int n, m, ans, Dp[M][N];

inline int Inc(int u, int v)
{
	return u >= Mod - v ? u - (Mod - v) : u + v;
}

int main()
{
	scanf("%d%d", &n, &m);
	Dp[0][1] = 1;
	for (int i = 1; i <= m; i ++)
		for (int j = 1, sum = 0; j <= n; j ++)
		{
			sum = Inc(sum, Dp[i - 1][j]);
			Dp[i][j] = sum;
		}
	int sum = 0;
	for (int i = 1; i <= n; i ++)
		sum = Inc(sum, Dp[m][i]);
	for (int i = 1; i <= n; i ++)
	{
		ans = (1LL * Dp[m][i] * sum + ans) % Mod;
		sum = Inc(sum, Mod - Dp[m][n - i + 1]);
	}
	printf("%d\n", ans);
	return 0;
}