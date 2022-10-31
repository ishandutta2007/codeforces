#include<bits/stdc++.h>
using namespace std;

const int N = 17;
const int M = 32770;
const int inf = 1e9;

int n, a[N], bin[N], low[M][N], f[N][N][M], pos[N][N][M], sta[N][N][M], id[N], s[M];

void init()
{
	bin[0] = 1;
	for (int i = 1; i <= 15; i++) bin[i] = bin[i - 1] * 2;
	for (int i = 1; i < bin[15]; i++)
		for (int j = 0; j <= 16; j++)
			for (int k = j; k <= 15; k++)
				if (k && (i & bin[k - 1]))
				{
					low[i][j] = k;
					break;
				}
}

void pre()
{
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			for (int k = 0; k < bin[n]; k++)
				f[i][j][k] = inf;
	f[0][0][0] = 0;
	for (int i = 1; i < bin[n]; i++)
		s[i] = s[i - bin[low[i][0] - 1]] + a[low[i][0]];
}

void pri(int i, int j, int k)
{
	if (!i) return;
	pri(i - 1, pos[i][j][k], k - sta[i][j][k]);
	for (int l = 1; l <= n; l++)
		if ((bin[l - 1] & sta[i][j][k]) && l != j)
		{
			printf("%d %d\n", id[l], id[j]);
			for (int u = l; u <= n; u++) id[u]--;
		}
}

int main()
{
	init();
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		pre();
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				for (int k = 0; k < bin[n]; k++)
				{
					if (f[i][j][k] == inf) continue;
					for (int t = k ^ (bin[n] - 1), l = t; l; l = (l - 1) & t)
						if (low[l][j + 1] > 0 && s[l] > f[i][j][k] && s[l] < f[i + 1][low[l][j + 1]][k ^ l])
						{
							f[i + 1][low[l][j + 1]][k ^ l] = s[l];
							sta[i + 1][low[l][j + 1]][k ^ l] = l;
							pos[i + 1][low[l][j + 1]][k ^ l] = j;
						}
				}
		int mx = 0, p1;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (f[i][j][bin[n] - 1] < inf) mx = i, p1 = j;
		printf("%d\n", n - mx);
		for (int i = 1; i <= n; i++) id[i] = i;
		pri(mx, p1, bin[n] - 1);
	}
	return 0;
}