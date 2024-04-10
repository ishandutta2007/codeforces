#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=505;

int n, m;
int vis[N], store[N];
set<int> g[N];

void dfs(int i, int tim)
{
	if(vis[i])
	{	
		int diff=tim - store[i];
		if(diff%2)
		{
			cout<<"No";
			exit(0);
		}
		return;
	}
	vis[i]=1;
	store[i]=tim;
	for(auto it:g[i])
		dfs(it, tim+1);
}

int32_t main()
{
	IOS;
	memset(store, -1, sizeof(store));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)
				continue;
			g[i].insert(j);
		}
	}
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].erase(v);
		g[v].erase(u);
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
			continue;
		dfs(i, 0);
	}
	for(int i=1;i<=n;i++)
	{
		if(g[i].size()==0)
			store[i]=-1;
	}	
	for(int i=1;i<=n;i++)
	{
		if(store[i]==-1)
			store[i]=1;
		else if(store[i]%2)
			store[i]=0;
		else
			store[i]=2;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)
				continue;
			if(g[i].find(j)!=g[i].end())
			{
				if(abs(store[j]-store[i])<=1)
				{
					cout<<"No";
					exit(0);
				}
			}
			else
			{
				if(abs(store[j]-store[i])>1)
				{
					cout<<"No";
					exit(0);
				}
			}
		}
	}
	cout<<"Yes"<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<(char)('a' + store[i]);
	}
	return 0;
}