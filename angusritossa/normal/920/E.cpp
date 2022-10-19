#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[200010];
int comp[200010];
vector<int> comps;
int seen[200010], upto;
vector<int> s;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) s.push_back(i);
	for (int i = 1; i <= n; i++)
	{
		if (comp[i]) continue;
		comp[i] = i;
		queue<int> q;
		q.push(i);
		int sz = 0;
		while (!q.empty())
		{
			int a = q.front();
			q.pop();
			sz++;
			upto+=2;
			for (int b : adj[a])
			{
				seen[b] = upto;
			}
			for (int b : s)
			{
				if (comp[b]) continue;
				if (seen[b] == upto)
				{
					seen[b] = upto+1;
					continue;
				}
				comp[b] = comp[a];
				q.push(b);
			}
			s.clear();
			for (int b : adj[a])
			{
				if (seen[b] == upto+1) s.push_back(b);
			}
		}
		comps.push_back(sz);
	}
	sort(comps.begin(), comps.end());
	printf("%d\n", comps.size());
	for (int i : comps)
	{
		printf("%d ", i);
	}
	printf("\n");
}