#include <bits/stdc++.h>
using namespace std;
int a[110], b[110], grid[110][110], n, m;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) scanf("%d", &b[i]);
	for (int j = 0; j < 30; j++)
	{
		vector<int> rows, cols;
		for (int i = 0; i < n; i++)
		{
			if (a[i] & (1 << j)) rows.push_back(i);
		}
		for (int i = 0; i < m; i++)
		{
			if (b[i] & (1 << j)) cols.push_back(i);
		}
		if (abs((int)rows.size() - (int)cols.size()) % 2)
		{
			printf("NO\n");
			return 0;
		}
		int mn = min(rows.size(), cols.size());
		for (int i = 0; i < mn; i++)
		{
			grid[rows[i]][cols[i]] |= (1 << j);
		}
		if (rows.size() > cols.size())
		{
			for (int i = mn; i < rows.size(); i++)
			{
				grid[rows[i]][0] |= (1 << j);
			}
		}
		if (cols.size() > rows.size())
		{
			for (int i = mn; i < cols.size(); i++)
			{
				grid[0][cols[i]] |= (1 << j);
			}
		}
	}
	printf("YES\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) printf("%d ", grid[i][j]);
		printf("\n");
	}
}