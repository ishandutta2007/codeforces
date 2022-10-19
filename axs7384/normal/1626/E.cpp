#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int a[N],f[N];
vector<int> e[N],g[N];
int n;
inline void dfs(int x,int y)
{
	f[x]=a[x];
	for (int z:e[x])
		if (z!=y)
		{
			dfs(z,x);
			f[x]+=f[z];
		}
}
inline void dfs0(int x,int y)
{
	for (int z:e[x])
		if (z!=y)
		{
			dfs0(z,x);
			if (a[z]||f[z]>=2)
				g[z].push_back(x);
			if (a[x]||f[1]-f[z]>=2)
				g[x].push_back(z);
		}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for (int i=1,u,v;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	dfs0(1,0);
	queue<int> q;
	for (int i=1;i<=n;++i)
		if (a[i])
			q.push(i);
	while (!q.empty())
	{
		int x=q.front();
		q.pop();
		for (int y:g[x])
			if (!a[y])
			{
				a[y]=1;
				q.push(y);
			}
	}
	for (int i=1;i<=n;++i)
		printf("%d%c",a[i],i==n?'\n':' ');
	return 0;
}