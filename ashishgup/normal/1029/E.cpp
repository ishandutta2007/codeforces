#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, ans=0;
int cache[N][5];
vector<int> g[N];

int dfs(int k, int par, int lvl)
{
	if(lvl<-1)
		return 1e9;
	int &ans=cache[k][lvl+2];
	if(ans!=-1)
		return ans;
	if(k!=1 && g[k].size()==1)
	{
		if(lvl<0)
			return 1;
	}
	int cost=0;
	for(auto &it:g[k])
	{
		if(it==par)
			continue;
		cost+=min(dfs(it, k, lvl-1), 1 + dfs(it, k, 1));
	}
	ans=cost;
	int curcost=0;
	for(auto &it:g[k])
	{
		if(it==par)
			continue;
		curcost+=min(dfs(it, k, max(lvl-1, -1LL)), 1 + dfs(it, k, 1));
	}
	for(auto &it:g[k])
	{
		if(it==par)
			continue;
		int temp=curcost;
		temp-=min(dfs(it, k, max(lvl-1, -1LL)), 1 + dfs(it, k, 1));
		temp+=1 + dfs(it, k, 1);
		ans=min(ans, temp);
	}
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cout<<dfs(1, 0, 2);
	return 0;
}