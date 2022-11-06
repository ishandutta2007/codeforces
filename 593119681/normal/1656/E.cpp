#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 100000 + 5

int Case, n, Ans[N];
vector<int> Vec[N];

void dfs(int z, int fa, int op)
{
	Ans[z] = op * int(Vec[z].size());
	for (int d : Vec[z])
		if (d != fa)
			dfs(d, z, -op);
}

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++)
			Vec[i].clear();
		for (int i = 1, u, v; i < n; i ++)
		{
			scanf("%d%d", &u, &v);
			Vec[u].push_back(v);
			Vec[v].push_back(u);
		}
		dfs(1, 0, 1);
		for (int i = 1; i <= n; i ++)
			printf("%d%c", Ans[i], i == n ? '\n' : ' ');
	}
	return 0;
}