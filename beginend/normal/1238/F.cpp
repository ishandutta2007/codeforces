#include<bits/stdc++.h>

const int N=300005;

int n,cnt,last[N],deg[N],f[N],ans;
struct edge{int to,next;}e[N*2];

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

void dfs(int x,int fa)
{
	int mx1=0,mx2=0;
	for (int i=last[x];i;i=e[i].next)
	{
		if (e[i].to==fa) continue;
		dfs(e[i].to,x);
		if (f[e[i].to]>mx1) mx2=mx1,mx1=f[e[i].to];
		else if (f[e[i].to]>mx2) mx2=f[e[i].to];
	}
	f[x]=mx1+deg[x];
	ans=std::max(ans,f[x]+mx2);
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		cnt=0;
		for (int i=1;i<=n;i++) deg[i]=last[i]=0;
		for (int i=1;i<n;i++)
		{
			int x,y;scanf("%d%d",&x,&y);
			addedge(x,y);deg[x]++;deg[y]++;
		}
		for (int i=1;i<=n;i++) deg[i]--;
		ans=0;dfs(1,0);
		printf("%d\n",ans+2);
	}
	return 0;
}