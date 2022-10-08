#include <stdio.h>
#include <string.h>

char str[1001][5];

int main ()
{
	int n;

	scanf ("%d", &n);

	strcpy(str[0], "1000");
	for (int i = 1; i <= n; i ++)
	{
		scanf ("%s", str[i]);

		char ans[5];

		strcpy(ans, "9999");

		for (int j = 0; j < 4; j ++)
			for (int l = 0; l < 10; l ++)
			{
				char tmp = str[i][j];

				str[i][j] = '0' + l;

				if (strcmp(str[i - 1], str[i]) <= 0 && strcmp(str[i], ans) < 0)
					strcpy(ans, str[i]);

				str[i][j] = tmp;
			}
		
		strcpy(str[i], ans);
//		printf ("%d %s\n", i, ans);
	}

	if (strcmp(str[n], "2011") <= 0)
		for (int i = 1; i <= n; i ++)
			printf ("%s\n", str[i]);
	else
		printf ("No solution\n");

	return 0;
}