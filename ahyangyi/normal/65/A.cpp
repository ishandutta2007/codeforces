#include <stdio.h>

int main ()
{
	int a, b, c, d, e, f;

	scanf ("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);

	if (b * d * f > a * c * e)
		printf ("Ron\n");
	else
		if (b * d * f == a * c * e && b * d * f == 0)
		{
			if (!c && d)
				printf ("Ron\n");
			else
				if (!a && b && c && d)
					printf ("Ron\n");
				else
					printf ("Hermione\n");
		}
		else
			printf ("Hermione\n");

	return 0;
}