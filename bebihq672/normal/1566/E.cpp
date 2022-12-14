#include<bits/stdc++.h>
using namespace std;

vector<int> G[202020];

int ans;

int dfs(int u, int fa)
{
	int ret = 0;
	for(int v: G[u])
	{
		if(v == fa)
			continue;
		ret |= dfs(v, u) ^ 1;
	}
	if(ret == 0)
		ans++;
	if(ret == 1 && u != 1)
		ans--;
	return ret;
}

int main()
{
    int T;
    scanf("%d", &T);
	while(T--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			G[i].clear();
		for(int i = 1; i < n; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		ans = 0;
		dfs(1, 0);
		printf("%d\n", ans);
	}
}