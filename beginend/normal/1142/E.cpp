#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define pb push_back

const int N=100005;

int n,m,cnt,last[N],low[N],dfn[N],tim,stack[N],top,bel[N],ret[N],a[N],sz,ls[N],nx[N],pos[N],deg[N],tot;
bool ins[N];
struct edge{int from,to,next;}e[N];
std::vector<int> vec[N],pts[N];

void addedge(int u,int v)
{
	e[++cnt].from=u;e[cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
}

void tarjan(int x)
{
	dfn[x]=low[x]=++tim;
	stack[++top]=x;ins[x]=1;
	for (int i=last[x];i;i=e[i].next)
		if (!dfn[e[i].to]) tarjan(e[i].to),low[x]=std::min(low[x],low[e[i].to]);
		else if (ins[e[i].to]) low[x]=std::min(low[x],dfn[e[i].to]);
	if (dfn[x]==low[x])
	{
		tot++;int y=0;
		while (y!=x)
		{
			y=stack[top--];ins[y]=0;
			bel[y]=tot;pts[tot].pb(y);
		}
		ret[tot]=pts[tot].size();
	}
}

void add(int x)
{
	for (int i=0;i<pts[x].size();i++)
	{
		int y=pts[x][i];
		a[++sz]=y;pos[y]=sz;
		ls[sz]=ls[n+1];nx[sz]=n+1;
		nx[ls[sz]]=ls[n+1]=sz;
	}
}

void del(int x)
{
	nx[ls[x]]=nx[x];ls[nx[x]]=ls[x];
	x=bel[a[x]];ret[x]--;
	if (!ret[x])
	{
		for (int i=0;i<vec[x].size();i++)
		{
			deg[vec[x][i]]--;
			if (!deg[vec[x][i]]) add(vec[x][i]);
		}
	}
}

int ask(int x,int y)
{
	printf("? %d %d\n",x,y);
	fflush(stdout);
	int k;scanf("%d",&k);
	return k;
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
	for (int i=1;i<=m;i++)
	{
		int x=bel[e[i].from],y=bel[e[i].to];
		if (x!=y) vec[x].pb(y),deg[y]++;
	}
	int tp=0;
	for (int i=1;i<=n;i++) if (!deg[bel[i]]) {tp=i;break;}
	for (int i=1;i<=tot;i++) if (!deg[i]) add(i);
	for (int i=1;i<=sz;i++) nx[i]=i+1,ls[i]=i-1;
	nx[0]=1;ls[n+1]=sz;nx[sz]=n+1;
	while (1)
	{
		if (bel[a[nx[0]]]==bel[tp]&&bel[a[ls[n+1]]]==bel[tp]) {printf("! %d\n",tp);fflush(stdout);return 0;}
		if (bel[a[nx[0]]]!=bel[tp])
		{
			int y=nx[0];
			if (ask(tp,a[y])) del(y);
			else del(pos[tp]),tp=a[y];
		}
		else
		{
			int y=ls[n+1];
			if (ask(tp,a[y])) del(y);
			else del(pos[tp]),tp=a[y];
		}
	}
	return 0;
}