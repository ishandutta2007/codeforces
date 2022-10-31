#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
typedef long long LL;
const int maxn = 600005;

int ehead[maxn],ecnt;
struct edge {
	int u,v,w,next;
}edg[maxn];
void add(int u,int v,int w) {
	edg[++ecnt]=(edge){u,v,w,ehead[u]};
	ehead[u]=ecnt;
	edg[++ecnt]=(edge){v,u,w,ehead[v]};
	ehead[v]=ecnt;
}

int col[maxn],pos[maxn][3],n,m,tag=1,a[maxn];
bool dfs(int u)
{
	for (int v,j=ehead[u];j;j=edg[j].next)
	if (col[v=edg[j].v]<0) {col[v]=col[u]^edg[j].w;dfs(v);}
	else if (col[v]!=(col[u]^edg[j].w)) tag=0;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("problem.in","r",stdin);
		freopen("problem.out","w",stdout);
	#endif
	memset(col,-1,sizeof col);
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=m;i++) {
		int t,x;scanf("%d",&t);
		while (t--) {
			scanf("%d",&x);
			pos[x][++pos[x][0]]=i;
		}
	}
	for (int i=1;i<=n;i++)
		add(pos[i][1],pos[i][2],a[i]^1);
	for (int i=1;i<=m;i++)
	if (col[i]<0) {col[i]=0;dfs(i);}
	printf("%s",tag?"YES":"NO");
	return 0;
}