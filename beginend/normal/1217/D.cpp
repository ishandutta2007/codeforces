#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=5005;

int n,m,cnt,last[N],dep[N],dfn[N],low[N],stack[N],top,id[N],tot,col[N],tim;
bool ins[N];
struct edge{int from,to,next;}e[N];

void addedge(int u,int v)
{
	e[++cnt].from=u;e[cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
}

void tarjan(int x)
{
	dfn[x]=low[x]=++tim;
	stack[++top]=x;ins[x]=1;
	for (int i=last[x];i;i=e[i].next)
		if (!dfn[e[i].to]) dep[e[i].to]=dep[x]+1,tarjan(e[i].to),low[x]=std::min(low[x],low[e[i].to]);
		else if (ins[e[i].to]) low[x]=std::min(low[x],dfn[e[i].to]);
	if (dfn[x]==low[x])
	{
		tot++;int y=0;
		while (y!=x)
		{
			y=stack[top--];ins[y]=0;
			id[y]=tot;
		}
		for (int i=1;i<=m;i++)
			if (id[e[i].from]==tot&&id[e[i].to]==tot) col[i]=(dep[e[i].from]<dep[e[i].to]);
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i);
	int mx=0;
	for (int i=1;i<=m;i++) mx=std::max(mx,col[i]);
	printf("%d\n",mx+1);
	for (int i=1;i<=m;i++) printf("%d ",col[i]+1);
	return 0;
}