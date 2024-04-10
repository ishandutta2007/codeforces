#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005];
pair<int,int> dfs(int node,int p)
{
	pair<int,int> ret(-1,node);
	for (int u:v[node])
	{
		if (u!=p)
		ret=max(ret,dfs(u,node));
	}
	ret.first++;
	return ret;
}
int dist(int node,int p,int tar)
{
	if (node==tar)
	return 0;
	int ret=1e9;
	for (int u:v[node])
	{
		if (u!=p)
		ret=min(ret,1+dist(u,node,tar));
	}
	return ret;
}
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n,a,b,da,db;
		scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
		for (int i=1;i<=n;i++)
		v[i].clear();
		for (int i=1;i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		auto p=dfs(1,0),p2=dfs(p.second,0);
		puts((2*da>=db || 2*da>=p2.first || da>=dist(a,0,b))? "Alice":"Bob");
	}
}