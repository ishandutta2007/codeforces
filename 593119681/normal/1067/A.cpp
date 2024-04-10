#include <cstdio>
#include <algorithm>
using namespace std;
#define N 200000 + 5
#define K 200 + 5
#define Mod 998244353

int n, ans, A[N], Dp[2][K][2], Sum[K][2];

inline int Inc(int u, int v)
{
	return u + v - (u + v >= Mod ? Mod : 0);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	Dp[0][1][0] = 1;
	for (int i = 1; i <= 200; i ++)
		Sum[i][0] = 1;
	for (int i = 1; i <= n; i ++)
	{
		if (~A[i])
		{
			for (int j = 1; j <= 200; j ++)
				for (int k = 0; k < 2; k ++)
					if (!k || j <= A[i])
						Dp[1][A[i]][A[i] > j] = Inc(Dp[1][A[i]][A[i] > j], Dp[0][j][k]);
		}
		else
		{
			/* Brute
			for (int u = 1; u <= 200; u ++)
				for (int j = 1; j <= 200; j ++)
					for (int k = 0; k < 2; k ++)
						if (!k || j <= u)
							Dp[1][u][u > j] = Inc(Dp[1][u][u > j], Dp[0][j][k]);
			*/
			for (int u = 1; u <= 200; u ++)
			{
				Dp[1][u][0] = Inc(Dp[1][u][0], Inc(Sum[200][0], Mod - Sum[u - 1][0]));
				Dp[1][u][1] = Inc(Dp[1][u][1], Inc(Sum[u - 1][0], Sum[u - 1][1]));
				Dp[1][u][0] = Inc(Dp[1][u][0], Dp[0][u][1]);
			}
		}
		for (int j = 1; j <= 200; j ++)
			for (int k = 0; k < 2; k ++)
			{
				Dp[0][j][k] = Dp[1][j][k], Dp[1][j][k] = 0;
				Sum[j][k] = Inc(Sum[j - 1][k], Dp[0][j][k]);
			}
	}
	for (int j = 1; j <= 200; j ++)
		ans = Inc(ans, Dp[0][j][0]);
	printf("%d\n", ans);
	return 0;
}