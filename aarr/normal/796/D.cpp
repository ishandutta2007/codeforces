#include <iostream>

#include <vector>

#include <queue>

using namespace std;

int d;
const int N = 1000 * 1000 * 1000 + 7;
int dis[300005];
vector<pair<int, int> > adj[300005];
int pol[300005];
int polc[300005];
int mark[300005];
queue<int> q;
void dfs(int v)
{
	for(int i = 0; i < adj[v].size(); i ++)
	{
		if(dis[adj[v][i].first] == N && dis[v] < d && polc[adj[v][i].first] == 0)
		{
			//cout << v << " " << adj[v][i].first << endl;
			dis[adj[v][i].first] = dis[v] + 1;
			mark[adj[v][i].second] = 1;
			dfs(adj[v][i].first);
		}
	}
}
int main()
{
	int n, k, cnt = 0;
	cin >> n;
	cin >> k;
	cin >> d;
	for(int i = 1; i <= n; i ++)
	{
		dis[i] = N;
	}
	for(int i = 0; i < k; i ++)
	{
		cin >> pol[i];
		q.push(pol[i]);
		dis[pol[i]] = 0;
	}
	for(int i = 1; i < n; i ++)
	{
		int x, y;
		cin >> x;
		cin >> y;
		adj[x].push_back({y, i});
		adj[y].push_back({x, i});
	}
	while(q.size())
	{
		int v = q.front();
		q.pop();
		//cout << v << " " << dis[v] << endl;
		for(int i = 0; i < adj[v].size(); i ++)
		{
			if(dis[adj[v][i].first] == N && dis[v] < d)
			{
				//cout << v << " " << adj[v][i].first << endl;
				dis[adj[v][i].first] = dis[v] + 1;
				mark[adj[v][i].second] = 1;
				q.push(adj[v][i].first);
			}
		}
	}
	for(int i = 1; i < n; i ++)
	{
		if(mark[i] == 0)
		{
			cnt ++;
		}
	}
	cout << cnt << endl;
	for(int i = 1; i < n; i ++)
	{
		if(mark[i] == 0)
		{
			cout << i << " ";
		}
	}
	return 0;
}