#include <bits/stdc++.h>
using namespace std;
typedef map<int, int> mii;
vector<int> adj[1000010];
bool seen[1000010];
int ans[1000010], n;
mii* amounts[1000010];
pair<int, int> best[1000010];
mii* merge(mii* a, mii* b, int c)
{
	if (a->size() > b->size()) swap(a, b);
	for (auto it = a->begin(); it != a->end(); ++it)
	{
		(*b)[it->first] += it->second;
		int am = (*b)[it->first];
		pair<int, int> b = { am, -it->first };
		best[c] = max(best[c], b);
	}
	delete a;
	return b;
}
void dfs(int a, int d = 0)
{
	seen[a] = 1;
	(*amounts[a])[d]++;
	best[a] = { 1, -d };
	for (auto b : adj[a])
	{
		if (seen[b]) continue;
		dfs(b, d+1);
		best[a] = max(best[a], best[b]);
		amounts[a] = merge(amounts[a], amounts[b], a);
	}
	//printf("%d: %d %d\n", a, best[a].first, best[a].second);
	ans[a] = -best[a].second-d;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		amounts[i] = new map<int, int>();
	}
	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", ans[i]);
	}
}