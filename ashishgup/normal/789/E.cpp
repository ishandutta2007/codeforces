#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2005;
const int off = 1002;
 
int x, n;
int a[N];
set<int> s;
int vis[N], dist[N], ways[N];
set<int> g[N];
 
void bfs(int k)
{
	queue<int> q;
	q.push(k);
	ways[k] = 1;
	vis[k] = 1;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(auto it:g[node])
		{
			if(!vis[it])
			{
				dist[it] = dist[node] + 1;
				vis[it] = 1;
				ways[it] += ways[node];
				q.push(it);
			}
			else
			{
				if(dist[node] + 1 == dist[it])
					ways[it] += ways[node];
			}
		}
	}
}
 
 
int32_t main()
{
	IOS;
	cin >> x >> n;
	for(int i = 1; i <= n; i++)
	{
		int c;
		cin >> c;
		c -= x;
		if(c == 0)
		{
			cout << 1;
			return 0;
		}
		s.insert(c);
	}
	for(int sum = -1000; sum <= 1000; sum++)
	{
		for(auto &it:s)
		{
			if(sum + it >= -1000 && sum + it <= 1000)
				g[sum + off].insert(sum + it + off);
		}
	}
	bfs(off);
	int ans = 1e9;
	for(int sum = -1000; sum <= 1000; sum++)
	{
		if(vis[sum + off] && g[sum + off].find(off) != g[sum + off].end())
			ans = min(ans, dist[sum + off] + 1);
	}
	if(ans == 1e9)
		ans = -1;
	cout << ans;
	return 0;
}