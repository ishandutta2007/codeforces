#include <cstdio>
#include <algorithm>
using namespace std;
#define N 115 + 5

int n, m, Minx, Maxx, Miny, Maxy;
char s[N][N];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
		scanf("%s", s[i] + 1);
	Minx = n, Miny = m;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			if (s[i][j] == 'B')
			{
				Minx = min(Minx, i);
				Miny = min(Miny, j);
				Maxx = max(Maxx, i);
				Maxy = max(Maxy, j);
			}
	printf("%d %d\n", (Minx + Maxx) / 2, (Miny + Maxy) / 2);
	return 0;
}