#include<bits/stdc++.h>

const int N=1005;

int n,tot,cnt,last[N],deg[N];
bool vis[N];
struct edge{int to,next;}e[N*2];

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

int query(int x,int y)
{
	printf("? %d %d\n",x,y);
	fflush(stdout);
	int w;scanf("%d",&w);
	return w;
}

void pri(int x)
{
	printf("! %d\n",x);
	fflush(stdout);
}

void del(int x,int y)
{
	vis[x]=1;tot--;
	deg[x]=0;
	for (int i=last[x];i;i=e[i].next)
		if (!vis[e[i].to]) deg[e[i].to]--;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		addedge(x,y);
		deg[x]++;deg[y]++;
	}
	tot=n;
	while (tot>1)
	{
		int x=0,y=0;
		for (int i=1;i<=n;i++)
			if (deg[i]==1) y=x,x=i;
		int w=query(x,y);
		if (w==x||w==y) {pri(w);return 0;}
		del(x,w);del(y,w);
	}
	for (int i=1;i<=n;i++)
		if (!vis[i]) {pri(i);return 0;}
	return 0;
		
}