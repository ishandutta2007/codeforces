#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 500 + 5
#define INF 593119681

int n, m, k, Dp[N][N], Pos[N][N], T[N][N];
char Map[N][N];

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i ++)
		scanf("%s", Map[i] + 1);
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= m; j ++)
			if (Map[i][j] == '1')
				Pos[i][++ Pos[i][0]] = j;
		for (int j = 0; j <= k; j ++)
		{
			if (j >= Pos[i][0])
			{
				T[i][j] = 0;
				continue ;
			}
			T[i][j] = INF;
			for (int l = 1; l + Pos[i][0] - j - 1 <= Pos[i][0]; l ++)
				T[i][j] = min(T[i][j], Pos[i][l + (Pos[i][0] - j - 1)] - Pos[i][l] + 1);
		}
	}
	for (int j = 1; j <= k; j ++)
		Dp[0][j] = INF;
	for (int i = 1; i <= n; i ++)
		for (int j = 0; j <= k; j ++)
		{
			Dp[i][j] = INF;
			for (int l = 0; l <= j; l ++)
				Dp[i][j] = min(Dp[i][j], Dp[i - 1][l] + T[i][j - l]);
		}
	printf("%d\n", Dp[n][k]);
	return 0;
}