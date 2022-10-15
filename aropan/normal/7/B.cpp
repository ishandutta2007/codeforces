#include<cstdio>
#include<cstring>

const int MAXN = 111;
const int MAXL = 11;

char s[MAXL];
int n, m, k, x, l, id;
int a[MAXN];


int main()
{
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	scanf("%d %d\n", &k, &m);
	while (k--)
	{
		scanf("%s", &s);
		if (s[0] == 'a')
		{
			scanf("%d", &l);
			int x = 0;
			for (int i = 1; i <= m - l + 1; i++)
			{
				x = i;
				for (int j = 0; j < l; j++)
					if (a[i + j])
					{
						x = 0;
						break;
					}
				if (x) break;
			}

			if (x == 0)
			{
				puts("NULL");
			}
			else
			{
				id++;
				printf("%d\n", id);
				for (int i = 0; i < l; i++)
					a[x + i] = id;
			}
		}
		if (s[0] == 'e')
		{
			scanf("%d", &x);
			l = 0;
			for (int i = 1; i <= m; i++)
				if (a[i] == x)
				{
					l++;
					a[i] = 0;
				}
			if (l == 0 || x == 0) puts("ILLEGAL_ERASE_ARGUMENT");
		}              
		if (s[0] == 'd')
		{
			n = 1;
			for (int i = 1; i <= m; i++)
				if (a[i]) a[n++] = a[i];

			for (int i = n; i <= m; i++)
				a[i] = 0;
		}
		scanf("\n");
	}
}