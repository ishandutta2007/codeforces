#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 300000 + 5
#define M 10
#define S 256
#define INF 1000000000

int n, m, a, b, fullmask, A[N][M];

bool Check(int k, int *u = NULL, int *v = NULL)
{
	static int Tar[S], Vis[S];
	memset(Tar, 0, sizeof(Tar));
	memset(Vis, 0, sizeof(Vis));
	for (int i = 1; i <= n; i ++)
	{
		int mask = 0;
		for (int j = 0; j < m; j ++)
			if (A[i][j] >= k)
				mask |= (1 << j);
		if (mask == fullmask)
		{
			if (u != NULL)
				*u = *v = i;
			return true;
		}
		if (Tar[mask] != 0)
		{
			if (u != NULL)
				*u = i, *v = Tar[mask];
			return true;
		}
		if (Vis[mask]) continue ;
		for (int s = mask; s; s = (s - 1) & mask)
			Tar[fullmask ^ s] = i;
	}
	return false;
}

int main()
{
	scanf("%d%d", &n, &m);
	fullmask = (1 << m) - 1;
	for (int i = 1; i <= n; i ++)
		for (int j = 0; j < m; j ++)
			scanf("%d", A[i] + j);
	int l = 0, r = INF;
	while (l < r)
	{
		int mid = l + r + 1 >> 1;
		if (Check(mid))
			l = mid;
		else r = mid - 1;
	}
	Check(l, &a, &b);
	printf("%d %d\n", a, b);
	return 0;
}