#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=505;
const int M=1e5+5;

int n, m;
int vis[N], parent[N], U[M], V[M];
vector<pair<int, int> > g[N];
vector<int> store;

bool findLoop(int v, int edgeidx) //Checks if there is a loop and marks the edges in the found loop
{
	if(vis[v]==1)
	{
		store.push_back(edgeidx);
		int u=U[edgeidx];
		while(u!=v)
		{
			store.push_back(parent[u]);
			u=U[parent[u]];
		}
		return 1;
	}
	if(vis[v]==2)
		return 0;
	vis[v]=1;
	parent[v]=edgeidx;
	for(auto &it:g[v])
		if(findLoop(it.first,it.second))
			return 1;
	vis[v]=2;
	return 0;
}

bool checkLoop() //Checks if the directed graph contains any cycle
{
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			int check=findLoop(i, -1);
			if(check)
				return 1;
		}
	}
	return 0;
}

bool findLoop2(int v, int forbidden) //Checks if there is a loop and marks the edges in the found loop
{
	if(vis[v]==1)
		return 1;
	if(vis[v]==2)
		return 0;
	vis[v]=1;
	for(auto &it:g[v])
	{
		if(it.second==forbidden)
			continue;
		if(findLoop2(it.first, forbidden))
			return 1;
	}
	vis[v]=2;
	return 0;
}

bool checkLoop2(int forb)
{
	fill(vis+1, vis+n+1, 0);
	for(int i=1;i<=n;i++)
	{
		if(!vis[i] && findLoop2(i, forb))
			return 0;
	}
	return 1;
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		U[i]=u, V[i]=v;
		g[u].push_back({v, i});
	}
	if(!checkLoop())
		cout<<"YES";
	else
	{
		for(auto &it:store)
		{
			if(checkLoop2(it))
			{
				cout<<"YES";
				return 0;
			}
		}
		cout<<"NO";
	}
	return 0;
}