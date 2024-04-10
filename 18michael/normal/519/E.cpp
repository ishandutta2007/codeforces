#include<bits/stdc++.h>
#define Mx 16
using namespace std;
int n,q,edge_t=0;
int la[100002]={},dep[100002],siz[100002];
int fa[100002][18];
struct aaa
{
	int to,nx;
}edge[200002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int f,int d)
{
	fa[x][0]=f,dep[x]=d,siz[x]=1;
	for(int i=1;i<=Mx;++i)fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs(v,x,d+1),siz[x]+=siz[v];
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
	scanf("%d",&n);
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	dfs(1,0,1),scanf("%d",&q);
	for(int x,y,z;q--;)
	{
		scanf("%d%d",&x,&y);
		if(x==y)
		{
			printf("%d\n",n);
			continue;
		}
		if((dep[x]+dep[y])&1)
		{
			puts("0");
			continue;
		}
		if(dep[x]==dep[y])
		{
			for(int i=Mx;~i;--i)
				if(fa[x][i]!=fa[y][i])
					x=fa[x][i],y=fa[y][i];
			printf("%d\n",n-siz[x]-siz[y]);
			continue;
		}
		z=LCA(x,y);
		if(dep[x]<dep[y])swap(x,y);
		for(int i=Mx;~i;--i)
			if(dep[fa[y][i]]>=dep[z])
				x=fa[x][i],y=fa[y][i];
		z=((dep[x]-dep[y])>>1)-1;
		for(int i=Mx;~i;--i)
			if((z>>i)&1)
				x=fa[x][i];
		printf("%d\n",siz[fa[x][0]]-siz[x]);
	}
	return 0;
}