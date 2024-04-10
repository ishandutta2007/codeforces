#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1000003;

int n, m;
int a[N];
vector<int> g[N];
int c[N];
void dfs(int x, int k)
{
	int i, j, h;
	c[x] = k;
	for (i = 0; i < g[x].size(); ++i)
	{
		h = g[x][i];
		if(!c[h])
			dfs(h, k);
	}
}
vector<int> co[N];
vector<int> cot[N];
int ans[N];
int main()
{
	int i, j, k;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		ans[i] = a[i];
	}
	for (i = 0; i < m; ++i)
	{
		scanf("%d%d", &j, &k);
		g[j].push_back(k);
		g[k].push_back(j);
	}
	k = 0;
	for (i = 1; i <= n; ++i)
	{
		if (!c[i])
		{
			++k;
			dfs(i, k);
		}
		cot[c[i]].push_back(i);
		co[c[i]].push_back(a[i]);
	}
	int ii;
	for (i = 1; i <= k; ++i)
	{
		sort(co[i].begin(), co[i].end());
		for (j = co[i].size() - 1,ii=0; j >= 0; --j,++ii)
		{
			ans[cot[i][ii]] = co[i][j];
		}
	}
	for (i = 1; i <= n; ++i)
	{
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}