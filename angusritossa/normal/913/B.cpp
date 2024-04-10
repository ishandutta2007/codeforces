#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> adj[1010];
int sz[1010];
bool works;
int dfs(int a)
{
	int ans = 0;
	for (int b : adj[a])
	{
		ans += dfs(b);
	}
	if (!adj[a].size()) return 1;
	if (ans < 3) 
	{

		works = false;
		return 0;
	}
	return 0;
}
int main()
{
	scanf("%d", &n);
	works = true;
	for (int i = 0; i < n-1; i++)
	{
		int a;
		scanf("%d", &a);
		adj[a].push_back(i+2);
	}
	dfs(1);
	if (works) printf("Yes\n");
	else printf("No\n");
}