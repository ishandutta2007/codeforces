#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
typedef long long LL;
const int maxn = 1000005;
const int maxm = 1<<22;
const int inf = 1<<29;

void upd(int &x,int y) {if (x<y) x=y;}

int hs[maxm],tot,tb[maxn];

int ehead[maxn],ecnt;
struct edge{
	int v,next;
}edg[maxn];
void add(int u,int v) {
	edg[++ecnt]=(edge){v,ehead[u]};
	ehead[u]=ecnt;
}

int n,a[maxn],dep[maxn],id[maxn];
int ldfn[maxn],rdfn[maxn],idx;
int ms[maxn],sz[maxn],ans[maxn];
int ins[maxn][25];char str[25];
void dfs(int u) {
	sz[u]=1;
	for (int j=ehead[u];j;j=edg[j].next) {
		int v=edg[j].v;dep[v]=dep[u]+1;
		dfs(v);sz[u]+=sz[v];
		if (sz[ms[u]]<sz[v]) ms[u]=v;
	}
}
void solve(int u,int sto) {
	ldfn[u]=++idx;id[idx]=u;
	for (int v,j=ehead[u];j;j=edg[j].next)
	if ((v=edg[j].v)!=ms[u]) {
		solve(v,sto+1);
		upd(ans[u],ans[v]);
		for (int j=ldfn[v];j<=rdfn[v];j++)
			tb[ins[id[j]][1]]=-inf;
	}
	if (ms[u]) {
		solve(ms[u],sto);upd(ans[u],ans[ms[u]]);
	}
	rdfn[u]=idx;int res=0;
	
	for (int v,j=ehead[u];j;j=edg[j].next)
	if ((v=edg[j].v)!=ms[u]) {
		for (int j=ldfn[v];j<=rdfn[v];j++)
		for (int k=ins[id[j]][0];k>=1;k--)
			upd(res,dep[id[j]]+tb[ins[id[j]][k]]);
		for (int j=ldfn[v];j<=rdfn[v];j++)
			upd(tb[ins[id[j]][1]],dep[id[j]]);
	}
	for (int k=ins[u][0];k>=1;k--)
		upd(res,dep[u]+tb[ins[u][k]]);
	upd(tb[ins[u][1]],dep[u]);
	upd(ans[u],res-2*dep[u]);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("paths.in","r",stdin);
		freopen("paths.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int p,i=2;i<=n;i++) {
		scanf("%d %s",&p,str);
		add(p,i);a[i]=a[p]^(1<<(str[0]-'a'));
	}
	for (int i=1;i<=n;i++)
		if (!hs[a[i]]) hs[a[i]]=++tot;
	for (int i=1;i<=n;i++) {
		ins[i][++ins[i][0]]=hs[a[i]];
		for (int j=0;j<22;j++)
		if (int v=hs[a[i]^(1<<j)]) 
			ins[i][++ins[i][0]]=v;
	}
	for (int i=1;i<=tot;i++) tb[i]=-inf;
	dfs(1);solve(1,0);
	for (int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}