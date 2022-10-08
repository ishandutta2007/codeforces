#include <stdio.h>
#include <string.h>

char str[100], bname[100];
int p, m, a, b, c, d, e;
int best;

int main ()
{
	best = -100000000;
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i ++)
	{
		scanf ("%s%d%d%d%d%d%d%d", str, &p, &m, &a, &b, &c, &d, &e);
		int cur = p * 100 - m * 50 + a + b + c + d + e;

//		printf ("%s %d\n", str, cur);

		if (cur > best)
		{
			best = cur;
			strcpy(bname, str);
		}
	}

	printf ("%s\n", bname);

	return 0;
}