#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
const int maxn = 100005;

int ehead[maxn],ecnt,deg[maxn];
struct edge {
	int u,v,next;
}edg[maxn];
void add(int u,int v) {
	edg[++ecnt]=(edge){u,v,ehead[u]};
	ehead[u]=ecnt;deg[v]++;
}

int par[maxn],sz[maxn],tot[maxn];
int findp(int u) {
	return par[u]?par[u]=findp(par[u]):u;
}
void merge(int u,int v) {
	u=findp(u);v=findp(v);
	if (u!=v) par[v]=u,sz[u]+=sz[v];
}
int que[maxn],head,tail,n,m,ans;


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("technology.in","r",stdin);
		freopen("technology.out","w",stdout);
	#endif
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) sz[i]=1;
	for (int u,v,i=1;i<=m;i++)
		scanf("%d %d",&u,&v),add(u,v),merge(u,v);
	head=0;tail=-1;
	for (int i=1;i<=n;i++)
		if (!deg[i]) que[++tail]=i;
	while (head<=tail) {
		int u=que[head++];
		tot[findp(u)]++;
		for (int v,j=ehead[u];j;j=edg[j].next)
			if (!--deg[v=edg[j].v]) que[++tail]=v;
	}
	
	for (int i=1;i<=n;i++)
		if (!par[i]) ans+=sz[i]-(sz[i]==tot[i]);
	printf("%d",ans);
	return 0;
}