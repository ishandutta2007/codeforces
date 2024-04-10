#include <bits/stdc++.h>
using namespace std;
bool seen[3050], oncycle[3010], cantgoto[3010];
vector<int> adj[3010];
void cant(int a)
{
	if (cantgoto[a]) return;
	cantgoto[a] = true;
	for (int i = 0; i < adj[a].size(); i++) cant(adj[a][i]);
}
vector<int> cycle;
map<pair<int, int>, vector<int> > m;
int ans[500010], k[500010], n, e, q;
void recurse(int a, int s)
{
	cycle.push_back(a);
	if (m.find(make_pair(s, a)) != m.end())
	{
	//	printf("%d %d %d\n", s, a, cycle.size());
		vector<int> next = m[make_pair(s, a)];
		if (cantgoto[a])
		{
			for (int i = 0; i < next.size(); i++) ans[next[i]] = -1;
		}
		else 
		{
			for(int i = 0; i < next.size(); i++) {
				if (k[next[i]] > cycle.size()) ans[next[i]] = -1;
				else ans[next[i]] = cycle[k[next[i]]-1];
			}
		}
		m.erase(make_pair(s, a));
	}
	if (oncycle[a])
	{
		for (int i = cycle.size()-1; cycle[i] != a; i--)
		{
			cant(cycle[i]);
		}
		cant(a);
	}
	if (seen[a]) { cycle.pop_back();return; }
	seen[a] = oncycle[a] = true;
	for (int i = 0; i < adj[a].size(); i++) recurse(adj[a][i], s);
	cycle.pop_back();
	oncycle[a] = false;
}
int main()
{
	scanf("%d%d%d", &n, &e, &q);
	for (int i = 0; i < e; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
	for (int i = 0; i < q; i++)
	{
		int a, b;
		scanf("%d%d%d", &a, &b, &k[i]);
		if (m.find(make_pair(a, b)) == m.end())
		{
			vector<int> v;
			v.push_back(i);
			m[make_pair(a, b)] = v;
		}
		else m[make_pair(a, b)].push_back(i);
	}
	for (int i = 1; i <= n; i++)
	{
		fill_n(seen, n+10, false);
		fill_n(oncycle, n+10, false);
		fill_n(cantgoto, n+10, false);
		recurse(i, i);
	}
	for (int i = 0; i < q; i++)
	{
		if (!ans[i]) printf("-1\n");
		else printf("%d\n", ans[i]);
	}
}