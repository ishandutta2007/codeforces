#include <stdio.h>

int best[101], ans[101];

int main ()
{
	int n, m;

	scanf ("%d%d", &n, &m);

	for (int i = 1; i <= n; i ++)
	{
		best[i] = 10000;
		ans[i] = 0;
	}

	for (int i = 0; i < m; i ++)
	{
		int l, r, t, c;

		scanf ("%d%d%d%d", &l, &r, &t, &c);
		for (int j = l; j <= r; j ++)
			if (t < best[j])
			{
				best[j] = t;
				ans[j] = c;
			}
	}

	int tot = 0;
	for (int i = 1; i <= n; i ++)
		tot += ans[i];

	printf ("%d\n", tot);

	return 0;
}