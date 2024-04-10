#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, m, k;
int a[N];
bool special[N];
vector<int> g[N];
int vis[N], level[N], vis2[N], level2[N];
vector<pair<int, int> > v;
multiset<int> s;

void bfs(int k)
{
	queue<int> q;
	q.push(k);
	vis[k] = 1;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(auto it:g[node])
		{
			if(!vis[it])
			{
				level[it] = level[node] + 1;
				vis[it] = 1;
				q.push(it);
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(special[i])
			v.push_back({level[i], i});
	}
}


void bfs2(int k)
{
	queue<int> q;
	q.push(k);
	vis2[k] = 1;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(auto it:g[node])
		{
			if(!vis2[it])
			{
				level2[it] = level2[node] + 1;
				vis2[it] = 1;
				q.push(it);
			}
		}
	}
}

int32_t main()
{
	IOS;
	cin >> n >> m >> k;
	for(int i = 1; i <= k; i++)
	{
		cin >> a[i];
		special[a[i]] = 1;
	}
	bool flag = 0;
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		if(special[u] && special[v])
			flag = 1;
		g[u].push_back(v);
		g[v].push_back(u);
	}	
	bfs(1);
	bfs2(n);
	if(flag)
	{
		cout << level[n];
		return 0;
	}	
	int ans = 0;
	sort(v.begin(), v.end());
	for(auto &it:v)
		s.insert(level2[it.second]);
	for(int i = 0; i + 1 < v.size(); i++)
	{
		s.erase(s.find(level2[v[i].second]));
		ans = max(ans, v[i].first + 1 + *s.rbegin());
	}
	ans = min(ans, level[n]);
	cout << ans;
	return 0;
}