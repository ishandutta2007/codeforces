#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int N=300005;
const int inf=1000000000;

int n,m,cnt,last[N],deg[N],pre[N],dis[N],a[N],tot,ans[N],tim,vis[N];
queue<int> que;
struct edge{int to,next;}e[N*2];

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

void bfs(int s)
{
	for (int i=1;i<=n;i++) dis[i]=inf;
	dis[s]=0;que.push(s);
	while (!que.empty())
	{
		int u=que.front();que.pop();
		for (int i=last[u];i;i=e[i].next)
			if (vis[e[i].to]==vis[s]&&dis[e[i].to]==inf)
			{
				dis[e[i].to]=dis[u]+1;
				pre[e[i].to]=u;
				que.push(e[i].to);
			}
	}
}

void dfs(int x)
{
	vis[x]=tim;a[++tot]=x;
	for (int i=last[x];i;i=e[i].next)
	{
		if (vis[e[i].to]!=tim&&vis[e[i].to]) continue;
		deg[x]++;
		if (!vis[e[i].to]) dfs(e[i].to);
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
	bfs(1);
	if (dis[n]<=4)
	{
		printf("%d\n",dis[n]);
		int t=0;
		for (int i=n;i!=1;i=pre[i]) ans[++t]=i;
		ans[++t]=1;
		while (t) printf("%d ",ans[t]),t--;
		return 0;
	}
	int s=0;
	for (int i=1;i<=n;i++) if (dis[i]==2) {s=i;break;}
	if (s)
	{
		int top=0;ans[++top]=n;ans[++top]=1;
		while (s!=1) ans[++top]=s,s=pre[s];
		ans[++top]=1;
		printf("%d\n",top-1);
		while (top) printf("%d ",ans[top]),top--;
		return 0;
	}
	vis[1]=tim=1;
	for (int i=last[1];i;i=e[i].next)
	{
		if (vis[e[i].to]) continue;
		tot=0;tim++;dfs(e[i].to);
		int s=0,t;
		for (int j=1;j<=tot;j++)
			if (deg[a[j]]!=tot-1) {s=a[j];break;}
		if (!s) continue;
		bfs(s);
		for (int j=1;j<=n;j++) if (dis[j]==2) {t=j;break;}
		int top=0;ans[++top]=n;ans[++top]=s;
		for (int x=t;x!=s;x=pre[x]) ans[++top]=x;
		ans[++top]=s;ans[++top]=1;
		printf("%d\n",top-1);
		while (top) printf("%d ",ans[top]),top--;
		return 0;
	}
	bfs(1);
	if (dis[n]==inf) {puts("-1");return 0;}
	int top=0;
	for (int x=n;x!=1;x=pre[x]) ans[++top]=x;
	ans[++top]=1;
	printf("%d\n",top-1);
	while (top) printf("%d ",ans[top]),top--;
	return 0;
}