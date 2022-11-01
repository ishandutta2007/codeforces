#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=100005;

int n,m,cnt,last[N],dep[N],fa[N],size[N],top[N];
struct edge{int to,next;}e[N*2];

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

void dfs1(int x)
{
	dep[x]=dep[fa[x]]+1;size[x]=1;
	for (int i=last[x];i;i=e[i].next)
	{
		if (e[i].to==fa[x]) continue;
		fa[e[i].to]=x;
		dfs1(e[i].to);
		size[x]+=size[e[i].to];
	}
}

void dfs2(int x,int chain)
{
	top[x]=chain;int k=0;
	for (int i=last[x];i;i=e[i].next)
		if (e[i].to!=fa[x]&&size[e[i].to]>size[k]) k=e[i].to;
	if (!k) return;
	dfs2(k,chain);
	for (int i=last[x];i;i=e[i].next)
		if (e[i].to!=fa[x]&&e[i].to!=k) dfs2(e[i].to,e[i].to);
}

int get_lca(int x,int y)
{
	while (top[x]!=top[y])
	{
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	if (dep[x]<dep[y]) return x;
	else return y;
}

int get_dis(int x,int y)
{
	int w=get_lca(x,y);
	return dep[x]+dep[y]-2*dep[w];
}

int solve(int x,int y,int z)
{
	int a=get_lca(x,y),b=get_lca(x,z),c=get_lca(y,z);
	if (dep[b]>dep[a]) a=b;
	if (dep[c]>dep[a]) a=c;
	return max(get_dis(x,a),max(get_dis(y,a),get_dis(z,a)))+1;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=2;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		addedge(i,x);
	}
	dfs1(1);
	dfs2(1,1);
	while (m--)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		printf("%d\n",solve(x,y,z));
	}
	return 0;
}