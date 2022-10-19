#include<bits/stdc++.h>
using namespace std;
const int N=200005;
const int K=100005;
vector<int> e[N];
int n,t,x,y;
int f[N];
inline void dfs(int x,int y,int p)
{
	if (p==0)
		f[x]=1+e[x].size();
	else
		f[x]=1-2*e[x].size();
	for (int z:e[x])
		if (z!=y)
			dfs(z,x,!p);
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<n;++i)
		{
			scanf("%d%d",&x,&y);
			e[x].push_back(y);
			e[y].push_back(x);
		}
		int mx=1;
		for (int i=2;i<=n;++i)
			if (e[i].size()>e[mx].size())
				mx=i;
		dfs(mx,0,0);
		for (int i=1;i<=n;++i)
			printf("%d ",f[i]);
		puts("");
		for (int i=1;i<=n;++i)
			e[i].clear();
	}
	return 0;
}