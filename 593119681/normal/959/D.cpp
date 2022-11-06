#include <cstdio>
#define N 1000000 + 5
#define M 10000000 + 5

int n, F[M], q[N], Fa[M];

void Prepare()
{
	F[1] = 1;
	for (int i = 2; i < M; i ++)
	{
		if (!F[i])
			q[++ q[0]] = F[i] = i;
		for (int j = 1; j <= q[0] && i * q[j] < M; j ++)
		{
			F[i * q[j]] = q[j];
			if (i % q[j] == 0) break ;
		}
	}
	for (int i = 2; i < M; i ++)
		Fa[i] = i;
}

int Find(int x)
{
	return x == Fa[x] ? x : Fa[x] = Find(Fa[x]);
}

int main()
{
	Prepare();
	scanf("%d", &n);
	for (int i = 1, lim = 1, x, _x; i <= n; i ++)
	{
		scanf("%d", &x);
		_x = x, x = Find(lim ? x : 2);
		for (int j = x, last = 0; j > 1; last = F[j], j /= F[j])
			if (last != F[j])
				for (int k = F[j]; k < M - 1; k += F[j])
					Fa[k] = Find(k + 1);
		printf("%d%c", x, i == n ? '\n' : ' ');
		lim &= (_x == x);
	}
	return 0;
}