#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>

using namespace std;
#define pb push_back
const int maxn = 600005;
const int inf = 1<<30;

bool ban[maxn];int col[maxn];
int n,m,c[maxn],go[maxn],tot;
int ehead[maxn],ecnt,lcnt=1;
struct edge {
	int u,v,next;
}edg[maxn];
void add(int u,int v) {
	edg[++ecnt]=(edge){u,v,ehead[u]};
	ehead[u]=ecnt;
	edg[++ecnt]=(edge){v,u,ehead[v]};
	ehead[v]=ecnt;
}

int cnt[maxn],sz[maxn],sum,vis[maxn],rt;
void getsize(int u,int par)
{
	sz[u]=1;cnt[u]=0;
	for (int v,j=ehead[u];j;j=edg[j].next)
	if (!vis[v=edg[j].v]&&v!=par) {
		getsize(v,u);sz[u]+=sz[v];
		cnt[u]=max(cnt[u],sz[v]);
	}
}
void getroot(int u,int par)
{
	for (int v,j=ehead[u];j;j=edg[j].next)
	if (!vis[v=edg[j].v]&&v!=par) getroot(v,u);
	cnt[u]=max(cnt[u],sum-sz[u]);
	if (cnt[u]<cnt[rt]) rt=u;
}
void solve(int u,int c)
{
	vis[u]=true;col[u]=c;
	for (int v,j=ehead[u];j;j=edg[j].next)
	if (!vis[v=edg[j].v]) {
		cnt[rt=0]=inf;getsize(v,u);
		sum=sz[v];getroot(v,u);
		solve(rt,c+1);
	}
}

struct line {
	int u,v,sub;
}l[maxn];
vector<int> e[maxn];
bool comp(int e1,int e2)
{
	return l[e1].v>l[e2].v;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("moriaty.in","r",stdin);
		freopen("moriaty.out","w",stdout);
	#endif
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) {
		l[++lcnt]=(line){i,i%n+1,0};
		l[++lcnt]=(line){i%n+1,i,0};
		e[i].pb(lcnt-1);e[i%n+1].pb(lcnt);
		ban[lcnt]=true;
	}
	for (int x,y,i=1;i<=m;i++) {
		scanf("%d %d",&x,&y);
		l[++lcnt]=(line){x,y,0};
		l[++lcnt]=(line){y,x,0};
		e[x].pb(lcnt-1);e[y].pb(lcnt);
	}
	for (int i=1;i<=n;i++) {
		sort(e[i].begin(),e[i].end(),comp);
		int sz=e[i].size();
		for (int j=0;j<sz;j++)
			go[e[i][j]^1]=e[i][(j+1)%sz];
	}
	for (int i=n;i>=1;i--) {
		int sz=e[i].size();
		for (int v,j=0;j<sz;j++)
		if (!ban[v=e[i][j]]&&!l[v].sub) {
			int sub=++tot;
			for (int k=v;!l[k].sub;k=go[k])
				l[k].sub=sub;
		}
	}
	for (int i=2;i<=lcnt;i+=2)
	if (!ban[i]&&!ban[i^1])
		add(l[i].sub,l[i^1].sub);
	solve(1,1);
	for (int i=tot;i>=1;i--)
		printf("%d ",col[i]);
	return 0;
}