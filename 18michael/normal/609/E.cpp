#include<bits/stdc++.h>
#define Mx 17
#define LL long long
using namespace std;
int n,m,edge_t=0;LL sum=0;
int la[200002]={},X[200002],Y[200002],Z[200002],id[200002],rt[200002],dep[200002];
int fa[200002][18],mx[200002][18];
struct aaa
{
	int to,nx,val;
}edge[400002];
inline bool cmp(int x,int y)
{
	return Z[x]<Z[y]? 1:0;
}
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],z},la[y]=edge_t;
}
inline void getroot(int x)
{
	if(rt[x]==x)return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
inline void dfs(int x,int f,int d)
{
	fa[x][0]=f,dep[x]=d;
	for(int i=1;i<=Mx;++i)fa[x][i]=fa[fa[x][i-1]][i-1],mx[x][i]=max(mx[x][i-1],mx[fa[x][i-1]][i-1]);
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			mx[v][0]=edge[i].val,dfs(v,x,d+1);
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=Mx;~i;--i)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	if(x==y)return x;
	for(int i=Mx;~i;--i)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)rt[i]=i;
	for(int i=1;i<=m;++i)scanf("%d%d%d",&X[i],&Y[i],&Z[i]),id[i]=i;
	sort(id+1,id+m+1,cmp);
	for(int i=1;i<=m;++i)
	{
		getroot(X[id[i]]),getroot(Y[id[i]]);
		if(rt[X[id[i]]]!=rt[Y[id[i]]])sum+=Z[id[i]],add_edge(X[id[i]],Y[id[i]],Z[id[i]]),rt[rt[X[id[i]]]]=rt[Y[id[i]]];
	}
	dfs(1,0,1);
	for(int i=1,z,t;i<=m;++i)
	{
		z=LCA(X[i],Y[i]),t=0;
		for(int j=Mx;~j;--j)
			if(dep[fa[X[i]][j]]>=dep[z])
				t=max(t,mx[X[i]][j]),X[i]=fa[X[i]][j];
		for(int j=Mx;~j;--j)
			if(dep[fa[Y[i]][j]]>=dep[z])
				t=max(t,mx[Y[i]][j]),Y[i]=fa[Y[i]][j];
		printf("%lld\n",sum-t+Z[i]);
	}
	return 0;
}