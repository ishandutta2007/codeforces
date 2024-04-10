#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 300000 + 5

int n, m, Ans[N], Id[N];
vector <int> Vec[N], S[N];

void dfs(int z, int last)
{
	for (int i = 0; i < S[z].size(); i ++)
	{
		int d = S[z][i];
		if (Ans[d]) Id[Ans[d]] = z;
	}
	int mex = 1;
	for (int i = 0; i < S[z].size(); i ++)
	{
		int d = S[z][i];
		if (Ans[d]) continue ;
		for (; Id[mex] == z; mex ++) ;
		Ans[d] = mex ++;
	}
	for (int i = 0; i < Vec[z].size(); i ++)
	{
		int d = Vec[z][i];
		if (d == last) continue ;
		dfs(d, z);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1, k; i <= n; i ++)
	{
		scanf("%d", &k);
		for (int j = 1, x; j <= k; j ++)
		{
			scanf("%d", &x);
			S[i].push_back(x);
		}
	}
	for (int i = 1, u, v; i < n; i ++)
	{
		scanf("%d%d", &u, &v);
		Vec[u].push_back(v);
		Vec[v].push_back(u);
	}
	dfs(1, 0);
	int Max = 0;
	for (int i = 1; i <= m; i ++)
	{
		if (!Ans[i]) Ans[i] = 1;
		Max = max(Max, Ans[i]);
	}
	printf("%d\n", Max);
	for (int i = 1; i <= m; i ++)
		printf("%d%c", Ans[i], i == m ? '\n' : ' ');
	return 0;
}