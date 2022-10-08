#include <stdio.h>

int n, V;
int a[20], b[20];

int main ()
{
	scanf ("%d%d", &n, &V);
	for (int i = 0; i < n; i ++)
	{
		scanf ("%d", a + i);
	}
	for (int i = 0; i < n; i ++)
	{
		scanf ("%d", b + i);
	}

	double porp = 1e20, totl = 0;
	for (int i = 0; i < n; i ++)
	{
		totl += a[i];
		if (b[i] / (double) a[i] < porp)
			porp = b[i] / (double) a[i];
	}

	if (porp * totl > V)
		printf ("%.11lf\n", (double) V);
	else
		printf ("%.11lf\n", porp * totl);
	
	return 0;
}