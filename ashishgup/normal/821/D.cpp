#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 1e5 + 5;
const int inf = 1e9;

int n, m, k;
int r[N], c[N];
map<pair<int, int>, int> idx;
vector<pair<int, int> > g[N];
set<int> row[N], col[N];
int dx[4] = {-1, +1, 0, 0};
int dy[4] = {0, 0, +1, -1};
int arrival[N], departure[N];

int dijkstra(int source, int arrival[], int departure[])
{
	for(int i = 1; i <= n + m + k; i++)
	{
		arrival[i] = inf;
		departure[i] = inf;
	}
	arrival[source] = 0;
	set<pair<int, int> > s;
	s.insert({0, source});
	while(!s.empty())
	{
		auto x = *(s.begin());
		s.erase(x);
		departure[x.second] = arrival[x.second];
		for(auto it:g[x.second])
		{
			if(arrival[it.first] > departure[x.second] + it.second)
			{
				s.erase({arrival[it.first], it.first});
				arrival[it.first] = departure[x.second] + it.second;
				s.insert({arrival[it.first], it.first});
			}
		}
	}
	int ans = min({arrival[k + n], arrival[k + n + m]});
	if(idx.find({n, m}) != idx.end())
		ans = min(ans, arrival[idx[{n, m}]]);
	if(ans == inf)
		ans = -1;
	return ans;
}

int32_t main()
{
	IOS;
	cin >> n >> m >> k;
	for(int i = 1; i <= k; i++)
	{
		cin >> r[i]	>> c[i];
		idx[{r[i], c[i]}] = i;
		row[r[i]].insert(i);
		col[c[i]].insert(i);
	}
	for(int i = 1; i <= k; i++)
	{
		for(int dir = 0; dir < 4; dir++)
		{
			int nx = r[i] + dx[dir];
			int ny = c[i] + dy[dir];
			if(idx.find({nx, ny}) != idx.end())
			{
				g[i].push_back({idx[{nx, ny}], 0});
			}
		}
	}
	int cur = k; //Node corresponding to this row
	for(int i = 1; i <= n; i++)
	{
		++cur;
		for(auto &it:row[i])
		{
			g[cur].push_back({it, 0});
			g[it].push_back({cur, 1});
			if(i != 1)
			{
				g[it].push_back({cur - 1, 1});
				g[cur - 1].push_back({it, 0});
			}
			if(i != n)
			{
				g[it].push_back({cur + 1, 1});
				g[cur + 1].push_back({it, 0});
			}
		}
	}
	//cur now points to node corresponding to column
	for(int i = 1; i <= m; i++)
	{
		++cur;
		for(auto &it:col[i])
		{
			g[cur].push_back({it, 0});
			g[it].push_back({cur, 1});
			if(i != 1)
			{
				g[it].push_back({cur - 1, 1});
				g[cur - 1].push_back({it, 0});
			}
			if(i != m)
			{
				g[it].push_back({cur + 1, 1});
				g[cur + 1].push_back({it, 0});
			}
		}
	}
	cout << dijkstra(1, arrival, departure);
	return 0;
}