#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=200005;

int n,m,cnt,last[N],a[N],deg[N],sg[N],h[N],sum[N];
bool vis[N];
struct edge{int to,next;}e[N];

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
}

void get_sg()
{
	int tot=0;
	for (int i=1;i<=n;i++) if (!deg[i]) a[++tot]=i;
	for (int i=1;i<=n;i++)
	{
		int x=a[i];
		for (int j=last[x];j;j=e[j].next)
		{
			deg[e[j].to]--;
			if (!deg[e[j].to]) a[++tot]=e[j].to;
		}
	}
	for (int i=n;i>=1;i--)
	{
		int x=a[i];
		for (int j=last[x];j;j=e[j].next) vis[sg[e[j].to]]=1;
		for (;vis[sg[x]];sg[x]++);
		for (int j=last[x];j;j=e[j].next) vis[sg[e[j].to]]=0;
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&h[i]);
	for (int i=1;i<=m;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		addedge(u,v);
		deg[v]++;
	}
	get_sg();
	for (int i=1;i<=n;i++) sum[sg[i]]^=h[i];
	int mx=-1;
	for (int i=n;i>=0;i--) if (sum[i]) {mx=i;break;}
	if (mx==-1) {puts("LOSE");return 0;}
	int pos=0;
	for (int i=1;i<=n;i++) if (sg[i]==mx&&(h[i]^sum[mx])<h[i]) {pos=i;break;}
	puts("WIN");
	h[pos]=sum[mx]^h[pos];
	for (int i=last[pos];i;i=e[i].next)
	{
		int x=e[i].to;
		if (vis[sg[x]]) continue;
		vis[sg[x]]=1;
		h[x]=sum[sg[x]]^h[x];
	}
	for (int i=1;i<=n;i++) printf("%d ",h[i]);
	puts("");
	return 0;
}