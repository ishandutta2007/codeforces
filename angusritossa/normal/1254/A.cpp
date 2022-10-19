#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
int grid[200][200], r, c, k;
char ans[200][200];
char kth(int a)
{
	if (a < 26) return 'a' + a;
	else if (a < 26*2) return 'A' + (a - 26);
	else return '0' + (a-26*2);
}
int main()
{
	int t;
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++)
	{
		scanf("%d%d%d", &r, &c, &k);
		int am = 0;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				char a;
				scanf(" %c", &a);
				if (a == 'R') grid[i][j] = 1;
				else grid[i][j] = 0;
				am += grid[i][j];
			}
		}
		int need = am/k;
		int upto = 0, have = 0;
		int remainder = am % k;
		for (int i = 0; i < r; i++)
		{
			if (i%2 == 0)
			{
				for (int j = 0; j < c; j++)
				{
					if (grid[i][j])
					{
						if ((upto < remainder && have == need+1) || (upto >= remainder && have == need))
						{
							D("%d\n", have);
							have = 0;
							upto++;
						}

						have++;
					}
					ans[i][j] = kth(upto);
				}
			}
			else
			{
				for (int j = c-1; j >= 0; j--)
				{
					if (grid[i][j])
					{
						if ((upto < remainder && have == need+1) || (upto >= remainder && have == need))
						{
							D("%d\n", have);
							have = 0;
							upto++;
						}
						have++;
					}
					ans[i][j] = kth(upto);
				}
			}
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++) printf("%c", ans[i][j]);
			printf("\n");
		}
	}
}