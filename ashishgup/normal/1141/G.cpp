#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 2e5 + 5;

int n, k, x, rem = 0, color = 0;
int ans[N], col[N], ctr[N];
set<int> contains[N];
bool bad[N];
vector<pair<int, int> > g[N];

void dfs(int u, int par)
{
	int count = 0, check = 0;
	for(auto &it:g[u])
	{
		if(it.first == par)
			continue;
		while(contains[u].find(color)!=contains[u].end() || contains[it.first].find(color)!=contains[it.first].end())
		{
			color++;
			color %= x;
		}
		col[it.second] = color%x;
		if(g[u].size() <= x)
			contains[u].insert(color);
		if(g[it.first].size() <= x)
			contains[it.first].insert(color);
		dfs(it.first, u);
	}
}

int check2(int cur)
{
	int rem = 0;
	for(int i=1;i<=n;i++)
		rem += (g[i].size() > cur);
	return rem <= k;
}

int check(int cur)
{
	memset(bad, 0, sizeof(bad));
	x = cur;
	rem = 0;
	color = 0;
	for(int i=1;i<=n;i++)
		contains[i].clear();
	dfs(1, 0);
	return rem <= k;
}	

int binsearch(int lo, int hi)
{
	while(lo < hi)
	{
		int mid = (lo + hi)/2;
		if(check2(mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	x = lo;
	check(lo);
	return lo;
}

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back({v, i});
		g[v].push_back({u, i});
	}
	int ans = binsearch(1, n-1);
	cout<<ans<<endl;
	for(int i=1;i<=n-1;i++)
	{
		if(!col[i])
			col[i] = ans;
		cout<<col[i]<<" ";
	}
	return 0;
}