#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=100005;

int n,cnt,last[N*2],w[N*2],tot,t[N*2],deg[N*2];
struct data{int l,r;}a[N];
struct edge{int to,next,use;}e[N*10];

void addedge(int u,int v)
{
	deg[u]++;deg[v]++;
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

void dfs(int x)
{
	for (int &i=last[x];i;i=e[i].next)
		if (!e[i].use&&!e[i^1].use)
		{
			deg[e[i].to]--;deg[e[i^1].to]--;
			e[i].use=1;dfs(e[i].to);
		}
}

int main()
{
	scanf("%d",&n);cnt=1;
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].l,&a[i].r);
		a[i].r++;w[++tot]=a[i].l;w[++tot]=a[i].r;
	}
	std::sort(w+1,w+tot+1);tot=std::unique(w+1,w+tot+1)-w-1;
	for (int i=1;i<=n;i++)
	{
		int l=std::lower_bound(w+1,w+tot+1,a[i].l)-w;
		int r=std::lower_bound(w+1,w+tot+1,a[i].r)-w;
		t[l]^=1;t[r]^=1;addedge(l,r);
	}
	tot++;w[tot]=w[tot-1];
	for (int i=1;i<tot;i++)
	{
		t[i]^=t[i-1];
		if (t[i]==1) addedge(i,i+1);
	}
	for (int i=1;i<=tot;i++) if (deg[i]&1) {puts("-1");return 0;}
	for (int i=1;i<=tot;i++)
		if (deg[i]) dfs(i);
	for (int i=1;i<=n;i++) printf("%d ",e[i*2].use);
	return 0;
}