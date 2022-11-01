#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=100005;

int n,m,h,u[N],deg[N],low[N],dfn[N],tim,bel[N],tot,ans,pos,stack[N],last[N],cnt,top,size[N];
struct edge{int to,next,from;}e[N*2];
bool ins[N];

void addedge(int u,int v)
{
    e[++cnt].from=u;e[cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
}

void tarjan(int x)
{
    dfn[x]=low[x]=++tim;
    stack[++top]=x;ins[x]=1;
    for (int i=last[x];i;i=e[i].next)
        if (!dfn[e[i].to]) tarjan(e[i].to),low[x]=min(low[x],low[e[i].to]);
        else if (ins[e[i].to]) low[x]=min(low[x],dfn[e[i].to]);
    if (dfn[x]==low[x])
    {
        tot++;int y=0;
        while (y!=x) y=stack[top--],bel[y]=tot,ins[y]=0,size[tot]++;
    }
}

int main()
{
	scanf("%d%d%d",&n,&m,&h);
	for (int i=1;i<=n;i++) scanf("%d",&u[i]);
	for (int i=1;i<=m;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		if ((u[x]+1)%h==u[y]) addedge(x,y);
		if ((u[y]+1)%h==u[x]) addedge(y,x);
	}
	ans=n+1;
	for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i);
	for (int i=1;i<=cnt;i++)
	{
		int x=bel[e[i].from],y=bel[e[i].to];
		if (x!=y) deg[x]++;
	}
	for (int i=1;i<=tot;i++) if ((!ans||size[i]<ans)&&!deg[i]) ans=size[i],pos=i;
	printf("%d\n",ans);
	for (int i=1;i<=n;i++) if (bel[i]==pos) printf("%d ",i);
	return 0;
}