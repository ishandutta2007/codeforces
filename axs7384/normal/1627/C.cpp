#include<bits/stdc++.h>
using namespace std;
const int N=200005;
vector<pair<int,int> > e[N];
int t,n;
int f[N];
inline void dfs(int x,int y,int z)
{
	for (auto v:e[x])
		if (v.first!=y)
		{
			f[v.second]=z;
			dfs(v.first,x,5-z);
		}
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
		{
			f[i]=0;
			e[i].clear();
		}
		for (int i=1,u,v;i<n;++i)
		{
			scanf("%d%d",&u,&v);
			e[u].push_back({v,i});
			e[v].push_back({u,i});
		}
		int b=0;
		for (int i=1;i<=n;++i)
			if (e[i].size()>2)
				b=1;
		if (b)
		{
			puts("-1");
			continue;
		}
		for (int i=1;i<=n;++i)
			if (e[i].size()==1)
			{
				dfs(i,0,2);
				break;
			}
		for (int i=1;i<n;++i)
			printf("%d%c",f[i],i==n-1?'\n':' ');
	}
	return 0;
}