#include<bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m, a[N][N], row[N], col[N], flag_row[N], flag_col[N], dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
char str[N];

void dfs(int x, int y)
{
	a[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int p = x + dx[i], q = y + dy[i];
		if (a[p][q]) dfs(p, q);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str + 1);
		for (int j = 1; j <= m; j++)
			if (str[j] == '.') a[i][j] = 0;
			else a[i][j] = 1, row[i] = col[j] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		int s = 0;
		for (int j = 1; j <= m; j++)
			if (a[i][j - 1] == 0 && a[i][j] == 1) s++;
		if (s > 1) {puts("-1"); return 0;}
	}
	for (int i = 1; i <= m; i++)
	{
		int s = 0;
		for (int j = 1; j <= n; j++)
			if (a[j - 1][i] == 0 && a[j][i] == 1) s++;
		if (s > 1) {puts("-1"); return 0;}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (!row[i] && !col[j]) flag_row[i] = flag_col[j] = 1;
	for (int i = 1; i <= n; i++)
		if (!row[i] && !flag_row[i]) {puts("-1"); return 0;}
	for (int i = 1; i <= m; i++)
		if (!col[i] && !flag_col[i]) {puts("-1"); return 0;}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j]) ans++, dfs(i, j);
	printf("%d\n", ans);
	return 0;
}