#include <cstdio>
#include <algorithm>
using namespace std;
#define N 5000 + 5
#define Mod 1000000007
#define Inv2 500000004

int n, A[N], Cnt[N], Down[N][N], _Down[N][N];

inline int Inc(int u, int v)
{
	return u + v - (u + v >= Mod ? Mod : 0);
}

int main()
{
	scanf("%d", &n);
	Cnt[1] = 1;
	for (int i = 1; i < n; i ++)
	{
		scanf("%d", A + i);
		Cnt[i + 1] = 1LL * Cnt[i] * A[i] % Mod;
	}
	for (int i = 1; i <= n; i ++)
		for (int j = 0; i + j <= n; j ++)
		{
			_Down[i][j] = !j ? 1 : 1LL * _Down[i][j - 1] * (j == 1 ? A[i + j - 1] - 1 : A[i + j - 1]) % Mod;
			Down[i][j] = !j ? 1 : 1LL * Down[i][j - 1] * A[i + j - 1] % Mod;
		}
	for (int i = 0; i <= n; i ++)
		for (int j = 0; j <= n; j ++)
			_Down[i][j] = Inc((!i || !j) ? 0 : _Down[i - 1][j - 1], _Down[i][j]);
	for (int k = 1; k <= 2 * n - 2; k ++)
	{
		int sum = 0;
		for (int i = max(1, k - n + 2); i <= n; i ++)
		{
			int res = 0;
			if (k < n) res = Down[i][k];
			int delta = max(1, k - n);
			res = Inc(res, _Down[i - delta][k - delta]);
			//for (int j = 1; j <= k && j < i; j ++)
			//	res = Inc(res, _Down[i - j][k - j]);
			res = 1LL * res * Cnt[i] % Mod;
			sum = Inc(sum, res);
		}
		sum = 1LL * sum * Inv2 % Mod;
		printf("%d%c", sum, k == 2 * n - 2 ? '\n' : ' ');
	}
	return 0;
}