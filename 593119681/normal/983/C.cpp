#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f

int n, Min = INF, Dp[2][10][10][10][10];

int main()
{
	scanf("%d", &n);
	memset(Dp, 0x3f, sizeof(Dp));
	Dp[0][1][0][0][0] = 0;
	for (int i = 1, u, v; i <= n; i ++)
	{
		scanf("%d%d", &u, &v);
		for (int cur = 1; cur <= 9; cur ++)
			for (int a = 0; a <= 9; a ++)
				for (int b = 0; b <= 9; b ++)
					for (int c = 0; c <= 9; c ++)
					{
						if (Dp[0][cur][a][b][c] == INF) continue ;
						int t = abs(cur - u);
						if (a == 0) Dp[1][u][v][b][c] = min(Dp[1][u][v][b][c], Dp[0][cur][a][b][c] + t);
						else
						{
							Dp[1][u][v][b][c] = min(Dp[1][u][v][b][c], Dp[0][cur][a][b][c] + abs(cur - a) + abs(a - u));
							Dp[1][a][v][b][c] = min(Dp[1][a][v][b][c], Dp[0][cur][a][b][c] + t + abs(u - a));
						}
						if (b == 0) Dp[1][u][a][v][c] = min(Dp[1][u][a][v][c], Dp[0][cur][a][b][c] + t);
						else
						{
							Dp[1][u][a][v][c] = min(Dp[1][u][a][v][c], Dp[0][cur][a][b][c] + abs(cur - b) + abs(b - u));
							Dp[1][b][a][v][c] = min(Dp[1][b][a][v][c], Dp[0][cur][a][b][c] + t + abs(u - b));
						}
						if (c == 0) Dp[1][u][a][b][v] = min(Dp[1][u][a][b][v], Dp[0][cur][a][b][c] + t);
						else
						{
							Dp[1][u][a][b][v] = min(Dp[1][u][a][b][v], Dp[0][cur][a][b][c] + abs(cur - c) + abs(c - u));
							Dp[1][c][a][b][v] = min(Dp[1][c][a][b][v], Dp[0][cur][a][b][c] + t + abs(u - c));
						}
						Dp[1][v][a][b][c] = min(Dp[1][v][a][b][c], Dp[0][cur][a][b][c] + t + abs(u - v));
					}
		for (int cur = 1; cur <= 9; cur ++)
			for (int a = 0; a <= 9; a ++)
				for (int b = 0; b <= 9; b ++)
					for (int c = 0; c <= 9; c ++)
						Dp[0][cur][a][b][c] = Dp[1][cur][a][b][c], Dp[1][cur][a][b][c] = INF;
		for (int T = 1; T <= 3; T ++)
		{
			for (int cur = 1; cur <= 9; cur ++)
				for (int a = 0; a <= 9; a ++)
					for (int b = 0; b <= 9; b ++)
						for (int c = 0; c <= 9; c ++)
						{
							if (Dp[0][cur][a][b][c] == INF) continue ;
							if (a) Dp[1][a][0][b][c] = min(Dp[1][a][0][b][c], Dp[0][cur][a][b][c] + abs(cur - a));
							if (b) Dp[1][b][a][0][c] = min(Dp[1][b][a][0][c], Dp[0][cur][a][b][c] + abs(cur - b));
							if (c) Dp[1][c][a][b][0] = min(Dp[1][c][a][b][0], Dp[0][cur][a][b][c] + abs(cur - c));
						}
			for (int cur = 1; cur <= 9; cur ++)
				for (int a = 0; a <= 9; a ++)
					for (int b = 0; b <= 9; b ++)
						for (int c = 0; c <= 9; c ++)
							Dp[0][cur][a][b][c] = min(Dp[0][cur][a][b][c], Dp[1][cur][a][b][c]);
		}
		for (int cur = 1; cur <= 9; cur ++)
			for (int a = 0; a <= 9; a ++)
				for (int b = 0; b <= 9; b ++)
					for (int c = 0; c <= 9; c ++)
						Dp[1][cur][a][b][c] = INF;
	}
	for (int cur = 1; cur <= 9; cur ++)
		Min = min(Min, Dp[0][cur][0][0][0]);
	printf("%d\n", Min + n * 2);
	return 0;
}