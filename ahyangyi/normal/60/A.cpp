#include <stdio.h>

int n, m;
char tmp[1000];

int main ()
{
	scanf ("%d%d", &n, &m);
	fgets(tmp, 1000, stdin);

	int min = 1, max = n;

	for (int i = 0; i < m; i ++)
	{
		fgets(tmp, 1000, stdin);
		if (tmp[7] == 'l')
		{
			int pos;

			sscanf (tmp + 15, "%d", &pos);
			if (pos - 1 < max) max = pos - 1;
		}
		else
		{
			int pos;

			sscanf (tmp + 16, "%d", &pos);
			if (pos + 1 > min) min = pos + 1;
		}
	}

	if (max >= min)
		printf("%d\n", max - min + 1);
	else
		printf ("-1\n");

	return 0;
}