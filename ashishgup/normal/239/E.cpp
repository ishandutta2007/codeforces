#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=3005;

int n, ans=3000;
vector<pair<int, int> > g[N];
int cache[N][2][2];

int dfs(int k, int par, int dir, int fin)
{
	int &ans=cache[k][dir][fin];
	if(ans!=-1)
		return ans;
	ans=0;
	int curcost=0;
	if(dir==0)
	{
		for(auto it:g[k])
		{	
			if(it.first==par)
				continue;
			curcost+=(it.second==1)+dfs(it.first, k, 0, 1);
		}
		ans=curcost;
		if(fin==0)
		{
			for(auto it:g[k])
			{
				if(it.first==par)
					continue;
				curcost-=(it.second==1)+dfs(it.first, k, 0, 1);
				curcost+=(it.second==1)+dfs(it.first, k, 1, 0);
				ans=min(ans, curcost);
				curcost+=(it.second==1)+dfs(it.first, k, 0, 1);
				curcost-=(it.second==1)+dfs(it.first, k, 1, 0);
			}
			for(auto it:g[k])
			{
				if(it.first==par)
					continue;
				curcost-=(it.second==1)+dfs(it.first, k, 0, 1);
				curcost+=(it.second==1)+dfs(it.first, k, 0, 0);
				ans=min(ans, curcost);
				curcost+=(it.second==1)+dfs(it.first, k, 0, 1);
				curcost-=(it.second==1)+dfs(it.first, k, 0, 0);
			}
		}
	}
	else
	{
		for(auto it:g[k])
		{	
			if(it.first==par)
				continue;
			curcost+=(it.second==1)+dfs(it.first, k, 0, 1);
		}
		ans=curcost;
		for(auto it:g[k])
		{
			if(it.first==par)
				continue;
			curcost-=(it.second==1)+dfs(it.first, k, 0, 1);
			curcost+=(it.second==0)+dfs(it.first, k, 1, 0);
			ans=min(ans, curcost);
			curcost+=(it.second==1)+dfs(it.first, k, 0, 1);
			curcost-=(it.second==0)+dfs(it.first, k, 1, 0);
		}
	}
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back({v, 0});
		g[v].push_back({u, 1});
	}
	for(int i=1;i<=n;i++)
	{
		memset(cache, -1, sizeof(cache));
		ans=min(ans, min(dfs(i, i, 0, 0), dfs(i, i, 1, 0)));
	}
	cout<<ans;
	return 0;
}