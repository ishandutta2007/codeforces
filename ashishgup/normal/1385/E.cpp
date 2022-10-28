#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 2e5 + 5;

int n, m;
int ans[N], t[N], stu[N], stv[N], pos[N];
vector<int> g[N];
vector<int> order; //Stores the Topological Order

bool toposort(int n) //Returns 1 if there exists a toposort, 0 if there is a cycle
{	
	order.clear();
	queue<int> q;
	vector<int> indeg(n + 1, 0);
	for(int i = 1; i <= n; i++)
		for(auto &it:g[i])
			indeg[it]++;
	for(int i = 1; i <= n; i++)
	{
		if(!indeg[i])
			q.push(i);
	}
	int idx = 0;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		order.push_back(u);
		idx++;
		pos[u] = idx;
		for(auto &v:g[u])
		{
			indeg[v]--;
			if(!indeg[v])
				q.push(v);
		}
	}
	return (order.size() == n);
}

int32_t main()
{
	IOS;
	int tc;
	cin >> tc;
	while(tc--)
	{
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			g[i].clear();
		for(int i = 1; i <= m; i++)
		{
			cin >> t[i] >> stu[i] >> stv[i];
			if(t[i] == 1)
				g[stu[i]].push_back(stv[i]);
		}
		if(!toposort(n))
		{
			cout << "NO" << endl;
			continue;
		}
		else
		{
			cout << "YES" << endl;
			for(int i = 1; i <= m; i++)
			{
				if(t[i] == 1)
					cout << stu[i] << " " << stv[i] << endl;
				else
				{
					if(pos[stu[i]] > pos[stv[i]])
						swap(stu[i], stv[i]);
					cout << stu[i] << " " << stv[i] << endl;
				}
			}
		}
	}
	return 0;
}