#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int N=1000005;
char ss[10];
int n;
int id[N];//0:And 1:Not   2;Xor
int son[N][2];
int f[N];
int calc (int x,int a,int b)
{
	if (id[x]==0) return a&b;
	if (id[x]==1) return (!a);
	if (id[x]==2) return a^b;
	if (id[x]==3) return a|b;
}
void dfs (int x)
{
/*	printf("%d %d %d\n",x,son[x][0],son[x][1]);
	system("pause");*/
	if (id[x]==4) return ;
	if (son[x][0]!=0) dfs(son[x][0]);
	if (son[x][1]!=0) dfs(son[x][1]);
	f[x]=calc(x,f[son[x][0]],f[son[x][1]]);
}
int g[N][2];
int fa[N];
int ans[N];
int o=0;
void dfs1 (int x)
{
	if (id[x]==4)
	{
		o=(son[fa[x]][0]==x);
		ans[x]=g[fa[x]][calc(fa[x],f[x]^1,f[son[fa[x]][o]])];
		return ;
	}
	if (fa[x]!=0)
	{
		o=(son[fa[x]][0]==x);
		g[x][0]=g[fa[x]][calc(fa[x],0,f[son[fa[x]][o]])];
	//	printf("x:%d fa:%d g[x][0]:%d other:%d %d %d\n",x,fa[x],g[x][0],f[son[fa[x]][o]],calc(fa[x],0,f[son[fa[x]][o]]));
		g[x][1]=g[fa[x]][calc(fa[x],1,f[son[fa[x]][o]])];
	}
	
	if (son[x][0]!=0) 
	{
		fa[son[x][0]]=x;
		dfs1(son[x][0]);
	}
	if (son[x][1]!=0) 
	{
		fa[son[x][1]]=x;
		dfs1(son[x][1]);
	}
}
int main()
{
	memset(ans,-1,sizeof(ans));
	memset(son,0,sizeof(son));
	scanf("%d",&n);
	for (int u=1;u<=n;u++)
	{
		scanf("%s",ss);
	//	printf("OZY:%s",ss);
		if (ss[0]=='A')
		{
			//printf("YES1\n");
			int x,y;
			scanf("%d%d",&x,&y);
			son[u][0]=x;son[u][1]=y;
			id[u]=0;
		}
		if (ss[0]=='N')
		{
			//printf("YES2\n");
			int x;
			scanf("%d",&x);
			son[u][0]=x;
			id[u]=1;
		}
		if (ss[0]=='X')
		{
			//printf("YES3\n");
			int x,y;
			scanf("%d%d",&x,&y);
			son[u][0]=x;son[u][1]=y;
			id[u]=2;
		}
		if (ss[0]=='O')
		{
			//printf("YES4\n");
			int x,y;
			scanf("%d%d",&x,&y);
			son[u][0]=x;son[u][1]=y;
			id[u]=3;
		}
		if (ss[0]=='I')
		{
			//printf("YES5\n");
			scanf("%d",&f[u]);
			id[u]=4;
		}
	}
	dfs(1);
/*	for (int u=1;u<=n;u++) printf("%d ",f[u]);
	printf("\n");*/
//	printf("YES\n");
	g[1][1]=1;g[1][0]=0;dfs1(1);
	for (int u=1;u<=n;u++)
		if (ans[u]!=-1)
			printf("%d",ans[u]);
	return 0;
}