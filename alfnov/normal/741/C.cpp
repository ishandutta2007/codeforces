#include<bits/stdc++.h>
using namespace std;
vector<int>g[200005];
int u[100005],v[100005],col[200005];
void dfs(int x)
{
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(!col[cu])
		{
			col[cu]=3-col[x];
			dfs(cu);
		}
	}
}
int main()
{
	srand(20090908);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		g[u[i]].push_back(v[i]);
		g[v[i]].push_back(u[i]);
	}
	for(int i=1;i<=2*n;i+=2)
	{
		g[i].push_back(i+1);
		g[i+1].push_back(i);
	}
	for(int i=1;i<=2*n;i++)if(!col[i])
	{
		col[i]=rand()%2+1;
		dfs(i);
	}
	for(int i=1;i<=n;i++)printf("%d %d\n",col[u[i]],col[v[i]]);
	return 0;
}