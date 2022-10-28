#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 2005;

int n, cur = 0;
int a[N][N];
int par[N], salary[N];

int32_t main()
{
	IOS;
	cin >> n;
	vector<pair<int, pair<int, int> > > costs;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			if(i == j)
				salary[i] = a[i][j], cur++;
			else
				costs.push_back({a[i][j], {i, j}});
		}
	}
	sort(costs.begin(), costs.end());
	vector<pair<int, int> > edges;
	for(auto &it:costs)
	{
		int u = it.second.first, v = it.second.second;
		int curCost = it.first;
		while(par[u])
			u = par[u];
		while(par[v])
			v = par[v];
		if(u == v)
			continue;
		if(salary[u] == curCost)
		{
			par[v] = u;
			edges.push_back({v, u});
		}
		else if(salary[v] == curCost)
		{
			par[u] = v;
			edges.push_back({u, v});
		}
		else
		{
			int newNode = ++cur;
			par[u] = par[v] = newNode;
			edges.push_back({v, newNode});
			edges.push_back({u, newNode});
			salary[newNode] = curCost;
		}
	}
	cout << cur << endl;
	for(int i = 1; i <= cur; i++)
		cout << salary[i] << " ";
	cout << endl;
	cout << cur << endl;
	for(auto &it:edges)
		cout << it.first << " " << it.second << endl;
	return 0;
}