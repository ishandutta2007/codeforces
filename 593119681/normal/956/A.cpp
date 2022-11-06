#include <bits/stdc++.h>
using namespace std;
#define N 50 + 5

int n, m;
char Map[N][N];
bool ok = 1;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
		scanf("%s", Map[i] + 1);
	for (int i = 1; ok && i < n; i ++)
		for (int j = i + 1; ok && j <= n; j ++)
			for (int u = 1; ok && u < m; u ++)
				for (int v = u + 1; ok && v <= m; v ++)
				{
					int tmp = (Map[i][u] == '#') + (Map[i][v] == '#') + (Map[j][u] == '#') + (Map[j][v] == '#');
					if (tmp == 3) ok = 0;
				}
	puts(ok ? "Yes" : "No");
	return 0;
}