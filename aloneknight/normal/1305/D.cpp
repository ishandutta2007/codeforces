#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int n,vis[1005],fa[1005][1005];
vector<int>g[1005];
int qry(int u,int v)
{
	printf("? %d %d\n",u,v);fflush(stdout);
	int w;scanf("%d",&w);return w;
}
void dfs(int x,int p)
{
	for(int y:g[x])if(y!=p)dfs(y,x);
	int lst=0;
	for(int y:g[x])if(y!=p&&!vis[y])
	{
		if(lst)
		{
			int w=qry(lst,y);
			if(w==x)fa[lst][x]=x,fa[y][x]=x;
			else if(w==y)fa[lst][x]=x,fa[x][y]=y;
			else if(w==lst)fa[y][x]=x,fa[x][lst]=lst;
			lst=0;
		}
		else lst=y;
	}
	if(lst)
	{
		if(!p)
		{
			int w=qry(lst,x);
			if(w==x)fa[lst][x]=x;
			else fa[x][lst]=lst;
			return;
		}
		vis[x]=1;int w=qry(lst,p);
		if(w==x)fa[lst][x]=x,fa[p][x]=x;
		else if(w==p)fa[lst][x]=x,fa[x][p]=p;
		else if(w==lst)fa[p][x]=x,fa[x][lst]=lst;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),g[u].pb(v),g[v].pb(u);
	dfs(1,0);
	for(int i=1;i<=n;i++)
	{
		int ff=1;
		for(int y:g[i])if(fa[y][i]!=i)ff=0;
		if(ff){printf("! %d\n",i);return 0;}
	}
	return 0;
}