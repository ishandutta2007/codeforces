#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m, ans=0, cur;
int a[12][N], vis[N], indeg[N];
map<int, int> g[N];
vector<int> newg[N];

void dfs(int k)
{
	cur++;
	for(auto &it:newg[k])
		dfs(it);
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(i==1 || (i>1 && g[a[i][j]].find(a[i][j+1])!=g[a[i][j]].end()))
				g[a[i][j]][a[i][j+1]]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(auto &it:g[i])
		{
			if(it.second==m)
			{
				indeg[it.first]++;
				newg[i].push_back(it.first);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{	
		if(!indeg[i])
		{
			cur=0;
			dfs(i);
			ans+=(cur*(cur+1)/2);
		}
	}
	cout<<ans;
	return 0;
}