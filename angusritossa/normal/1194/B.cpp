#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
typedef long long ll;
int n;
int aminrow[100010], amincol[100010];
vector<char> grid[100010];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int r, c;
		scanf("%d%d", &r, &c);
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				char a;
				scanf(" %c", &a);
				if (a == '*') aminrow[i]++, amincol[j]++;
				grid[i].push_back(a);
			}
		}
		int ans = 1e9;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				ans = min(ans, r+c-aminrow[i]-amincol[j] - (grid[i][j] == '.'));
			}
		}
		for (int i = 0; i < r; i++)
		{
			aminrow[i] = 0;
			grid[i].clear();
		}
		for (int i = 0; i < c; i++) amincol[i] = 0;
		printf("%d\n", ans);
	}
}