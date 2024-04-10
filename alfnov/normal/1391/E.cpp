#include<bits/stdc++.h>
using namespace std;
vector<int>g[500005],G[500005],h[500005];
int vist[500005],dep[500005],fa[500005];
int A[500005],B[500005],tt;
void dfs1(int x)
{
	vist[x]=1;
	for(int i=0;i<G[x].size();i++)
	{
		int cu=G[x][i];
		if(vist[cu])continue;
		g[x].push_back(cu);
		dfs1(cu);
	}
}
void dfs2(int x,int la)
{
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(cu==la)continue;
		dep[cu]=dep[x]+1,fa[cu]=x;
		dfs2(cu,x);
	}
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)G[i].clear(),g[i].clear();
		for(int i=1;i<=n;i++)vist[i]=0,h[i].clear();
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs1(1);
		dep[1]=1,fa[1]=0,dfs2(1,0);
		int W=0;
		for(int i=1;i<=n;i++)if(dep[i]>=(n+1>>1))
		{
			W=i;
			break;
		}
		if(W>0)
		{
			printf("PATH\n");
			printf("%d\n",dep[W]);
			while(W!=1)printf("%d ",W),W=fa[W];
			printf("%d\n",W);
			continue;
		}
		printf("PAIRING\n");
		tt=0;
		for(int i=1;i<=n;i++)h[dep[i]].push_back(i);
		for(int i=1;i<=n;i++)for(int j=1;j<h[i].size();j+=2)
		{
			int a=h[i][j-1],b=h[i][j];
			tt++;
			A[tt]=a,B[tt]=b;
		}
		printf("%d\n",tt);
		for(int i=1;i<=tt;i++)printf("%d %d\n",A[i],B[i]);
	}
	return 0;
}