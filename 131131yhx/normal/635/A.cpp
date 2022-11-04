#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

bool B[11][11];

int Sum[11][11], ans = 0;

int main()
{
	int r, c, n, K;
	scanf("%d%d%d%d", &r, &c, &n, &K);
	for(int i = 1; i <= n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		B[x][y] = 1;
	}
	for(int i = 1; i <= r; i++)
		for(int j = 1; j <= c; j++)
			Sum[i][j] = Sum[i - 1][j] + Sum[i][j - 1] - Sum[i - 1][j - 1] + B[i][j];
	for(int i = 1; i <= r; i++)
		for(int k = 0; k < i; k++)
			for(int j = 1; j <= c; j++)
				for(int s = 0; s < j; s++)
					if(Sum[i][j] - Sum[k][j] - Sum[i][s] + Sum[k][s] >= K) ans++;
	printf("%d\n", ans);
	return 0;
}