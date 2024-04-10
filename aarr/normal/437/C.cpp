#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

pair<int, int> a[1005];
int indeg[1005];
vector<int> adj[1005];
int main()
{
	int n, m;
	long long ans = 0;
	cin >> n;
	cin >> m;
	for(int i = 1; i <= n; i ++)
	{
		int x;
		cin >> x;
		a[i] = {x, i};
	}
	for(int i = 0; i < m; i ++)
	{
		int x, y;
		cin >> x;
		cin >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		indeg[x] ++;
		indeg[y] ++;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++)
	{
		int x = a[i].second;
		for(int i = 0; i < adj[x].size(); i ++)
		{
			indeg[adj[x][i]] --;
		}
		if(indeg[x] > 0)
		{
			ans += indeg[x] * a[i].first;
		}
	}
	cout << ans;
	return 0;
}