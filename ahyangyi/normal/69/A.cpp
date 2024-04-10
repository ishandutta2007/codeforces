#include <stdio.h>

int x, y, z;

int main ()
{
	int n;
	
	scanf ("%d", &n);

	x = y = z = 0;

	for (int i = 0; i < n; i ++)
	{
		int xx, yy, zz;

		scanf ("%d%d%d", &xx, &yy, &zz);

		x += xx;
		y += yy;
		z += zz;
	}

	if (x || y || z)
		printf ("NO\n");
	else
		printf ("YES\n");

	return 0;
}