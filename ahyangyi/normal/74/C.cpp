// This is actually C
#include <cstdio>
#include <cstring>

int n, m;
int visited[2000000];
int ans = 0;

void dfs (int x)
{
	int dir = 1;
	while (!visited[x])
	{
		visited[x] = 1;
//		if (x != 0 && x != n - 1)
//			visited[2 * n - 2 - x] = 1;
		x = (x + 2 * m - 2) % (2 * n - 2);
//		printf ("x = %d\n", x);
	}
}

int main ()
{
	scanf ("%d%d", &n, &m);

	if (n == 1 || m == 1)
		ans = n > m? n : m;
	else
	{
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < n; i ++)
		{
			if (!visited[i])
			{
//				printf ("%d\n", i);
				dfs(i);
				if (i != 0 && i != n - 1)
					dfs(n * 2 - 2 - i);
				ans ++;
			}
		}
	}

	printf ("%d\n", ans); //while (1);

	return 0;
}