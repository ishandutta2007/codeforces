#include <iostream>

#include <algorithm>

#include <vector>

#include <queue>

using namespace std;

queue<int> q;
vector <int> adj[500005];
vector<int> v1;
vector<int> v2;
int mark[500005];
vector <int> parts[500005];
int main()
{
	ios :: sync_with_stdio(false);
	int n, m, nparts = 1;
	cin >> n;
	cin >> m;
	for(int i = 0; i < m; i ++)
	{
		int x, y;
		cin >> x;
		cin >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i = 1; i <= n; i ++)
	{
		v1.push_back(i);
		sort(adj[i].begin(), adj[i].end());
	}
	while(v1.size())
	{
		int v = v1[v1.size() - 1];
		v1.pop_back();
		q.push(v);
		while(q.size())
		{
			int i = 0, j = 0;
			v = q.front();
			mark[v] = nparts;
			q.pop();
			while(i < v1.size() && j < adj[v].size())
			{
				bool b = true;
				if(v1[i] > adj[v][j])
				{
					j ++;
					b = false;
				}
				if(b && v1[i] == adj[v][j])
				{
					v2.push_back(v1[i]);
					b = false;
					i ++;
					j ++;
				}
				if(b && v1[i] < adj[v][j])
				{
					q.push(v1[i]);
					i ++;
				}
			}
			while(i < v1.size())
			{
				q.push(v1[i]);
				i ++;
			}
			v1.clear();
			for(int k = 0; k < v2.size(); k ++)
			{
				v1.push_back(v2[k]);
			}
			v2.clear();
		}
		nparts ++;
	}
	for(int i = 1; i <= n; i ++)
	{
		//cout << mark[i] << " ";
		parts[mark[i]].push_back(i);
	}
	cout << nparts - 1;
	for(int i = 1; i < nparts; i ++)
	{
		int siz = parts[i].size();
		cout << endl << siz << " ";
		for(int j = 0; j < siz; j ++)
		{
			cout << parts[i][j] << " ";
		}
	}
	return 0;
}