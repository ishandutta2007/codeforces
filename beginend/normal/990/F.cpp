#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>

const int N=200005;

int n,m,cnt,last[N],ans[N],s[N];
struct edge{int to,next,id;}e[N*2];
bool vis[N];

void addedge(int u,int v,int id)
{
    e[++cnt].to=v;e[cnt].id=id;e[cnt].next=last[u];last[u]=cnt;
    e[++cnt].to=u;e[cnt].id=-id;e[cnt].next=last[v];last[v]=cnt;
}

void dfs(int x)
{
	vis[x]=1;
	for (int i=last[x];i;i=e[i].next)
	{
		if (vis[e[i].to]) continue;
		dfs(e[i].to);
		ans[abs(e[i].id)]+=e[i].id>0?s[e[i].to]:-s[e[i].to];
		s[x]+=s[e[i].to];
	}
}

int main()
{
	scanf("%d",&n);
	int w=0;
	for (int i=1;i<=n;i++) scanf("%d",&s[i]),w+=s[i];
	if (w!=0) {puts("Impossible");return 0;}
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		addedge(x,y,i);
	}
	dfs(1);
	puts("Possible");
	for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}