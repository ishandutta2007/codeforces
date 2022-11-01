#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 30;

int n;
LL a[N][N], bin[N * 2], val[N][N];

void solve(int x, int y, LL w)
{
	if (x == 1 && y == 1)
	{
		printf("%d %d\n", x, y);
		fflush(stdout);
		return;
	}
	LL v = x > 1 ? val[x - 1][y] : val[x][y - 1];
	if (w & v)
	{
		if (x > 1 && a[x - 1][y]) solve(x - 1, y, w);
		else solve(x, y - 1, w);
	}
	else
	{
		if (x > 1 && !a[x - 1][y]) solve(x - 1, y, w);
		else solve(x, y - 1, w);
	}
	printf("%d %d\n", x, y);
	fflush(stdout);
}

int main()
{
	scanf("%d", &n);
	bin[0] = 1;
	for (int i = 1; i <= n * 2; i++) bin[i] = bin[i - 1] * 2;
	for (int i = 1; i <= n; i++)
	{
		int x = 1, y = i; LL w = 0;
		while (y >= 1) a[x][y] = w, val[x][y] = bin[i - 1], x++, y--, w ^= bin[i - 1];
	}
	for (int i = 2; i <= n; i++)
	{
		int x = i, y = n; LL w = 0;
		while (x <= n) a[x][y] = w, val[x][y] = bin[i - 2 + n], x++, y--, w ^= bin[i - 2 + n];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) printf("%lld ", a[i][j]);
		puts("");
		fflush(stdout);
	}
	int q; scanf("%d", &q);
	while (q--)
	{
		LL w; scanf("%lld", &w);
		solve(n, n, w);
	}
	return 0;
}