#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>

using namespace std;
typedef long long LL;
const LL mod = 1e9+7;
const int maxn = 1000005;
#define pb push_back

int ehead[maxn],ecnt;
struct edge {
	int u,v,next;
}edg[maxn];
void add(int u,int v)
{
	edg[++ecnt]=(edge){u,v,ehead[u]};
	ehead[u]=ecnt;
	edg[++ecnt]=(edge){v,u,ehead[v]};
	ehead[v]=ecnt;
}
vector<int> c[maxn];
int col[maxn],n,m,rt=1,s[maxn],usd[maxn];

void dfs(int u,int fa)
{
	for (int j=0;j<s[u];j++)
		usd[col[c[u][j]]]=u;
	for (int j=0,i=1;j<s[u];j++)
	if (!col[c[u][j]]) {
		while (usd[i]==u) ++i;
		col[c[u][j]]=i++;
	}
	for (int v,j=ehead[u];j;j=edg[j].next)
	if ((v=edg[j].v)!=fa) dfs(v,u); 
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("coloring.in","r",stdin);
		freopen("coloring.out","w",stdout);
	#endif
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
		(s[i]>s[rt])?rt=i:0;
		for (int v,j=1;j<=s[i];j++)
			scanf("%d",&v),c[i].pb(v);
	}
	for (int u,v,i=1;i<n;i++)
		scanf("%d %d",&u,&v),add(u,v);
	
	for (int j=0;j<s[rt];j++)
		col[c[rt][j]]=j+1;
	dfs(rt,0);
	printf("%d\n",max(1,s[rt]));
	for (int i=1;i<=m;i++)
		printf("%d ",col[i]?col[i]:1);
	return 0;
}