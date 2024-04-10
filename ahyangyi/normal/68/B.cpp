#include <stdio.h>

int n, k;
int a[10000];

bool test (double x)
{
	double balance = 0;

	for (int i = 0; i < n; i ++)
		if (a[i] >= x)
		{
			balance += (a[i] - x) * (100 - k) / 100;
		}
		else
		{
			balance -= (x - a[i]);
		}

	return balance >= 0;
}

int main ()
{
	scanf ("%d%d", &n, &k);
	for (int i = 0; i < n; i ++)
		scanf ("%d", a + i);

	double l, m, r;

	l = 0;
	r = 1000;
	while (l < r - 1e-11)
	{
		m = (l + r) / 2;
		if (test(m))
			l = m;
		else
			r = m;
	}

	printf ("%.14lf\n", (l + r) / 2);

	return 0;
}