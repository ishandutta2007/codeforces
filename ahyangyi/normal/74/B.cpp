#include <stdio.h>
#include <string.h>

int n, m, k, t;
char str[10], tm[300];
int pos[300];
int psb[300][50];

int main ()
{
	scanf ("%d%d%d%s%s%s", &n, &m, &k, str, str, tm);
	m --;
	k --;
	t = strlen(tm);

	int dir = str[0] == 't';

	pos[0] = k;
	for (int i = 1; i <= t; i ++)
	{
		if (dir && pos[i - 1] == n - 1) dir = !dir;
		if (!dir && pos[i - 1] == 0) dir = !dir;

		pos[i] = pos[i - 1] + (dir? 1 : -1);
	}

	memset(psb, 0, sizeof(psb));
	psb[0][m] = 1;

	for (int i = 0; i < t; i ++)
		if (tm[i] == '0')
		{
			// Moving
			for (int j = 0; j < n; j ++)
				if (psb[i][j])
				{
					if (pos[i + 1] != j)
						psb[i + 1][j] = 1;
					if (j + 1 < n && pos[i] != j + 1 && pos[i + 1] != j + 1)
						psb[i + 1][j + 1] = 1;
					if (j > 0 && pos[i] != j - 1 && pos[i + 1] != j - 1)
						psb[i + 1][j - 1] = 1;
				}
		}
		else
		{
			// Stopping

			bool surv = false;
			for (int j = 0; j < n; j ++)
				if (psb[i][j])
					surv = true;

			if (surv)
			{
				for (int j = 0; j < n; j ++)
					if (pos[i + 1] != j)
						psb[i + 1][j] = 1;
			}
		}

	for (int i = 0; i <= t; i ++)
	{
		pos[i] = 0;
		for (int j = 0; j < n; j ++)
			if (psb[i][j])
				pos[i] = 1;
	}

	{
		int i = 0;
		while (i <= t && pos[i]) i ++;

		if (i == t + 1)
			printf ("Stowaway\n");
		else
			printf ("Controller %d\n", i);
	}

	return 0;
}