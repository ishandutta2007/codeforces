#include<cstdio>
#include<algorithm>
#define Mx 17
using namespace std;
int n,m,edge_t=0;
int X[200002],Y[200002],Z[200002],id[200002],rt[200002],la[200002]={},dep[200002],ans[200002],num[200002];
bool u[200002]={};
int fa[200002][18],mx[200002][18];
struct aaa
{
	int to,nx,num;
}edge[400002];
inline bool cmp(int x,int y)
{
	return Z[x]<Z[y]? 1:0;
}
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],z},la[y]=edge_t;
}
inline void dfs(int x,int f,int d)
{
	fa[x][0]=f,rt[x]=x,dep[x]=d;
	for(int i=1;i<=Mx;++i)fa[x][i]=fa[fa[x][i-1]][i-1],mx[x][i]=max(mx[x][i-1],mx[fa[x][i-1]][i-1]);
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			mx[v][0]=Z[num[v]=edge[i].num]-1,dfs(v,x,d+1);
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
		getroot(X[id[i]]),getroot(Y[id[i]]),ans[i]=-1;
		if(rt[X[id[i]]]!=rt[Y[id[i]]])rt[rt[X[id[i]]]]=rt[Y[id[i]]],add_edge(X[id[i]],Y[id[i]],id[i]),u[id[i]]=1;
	}
	dfs(1,0,1);
	for(int i=1,j,z;i<=m;++i)
		if(!u[id[i]])
		{
			z=LCA(X[id[i]],Y[id[i]]),j=X[id[i]];
			for(int k=Mx;~k;--k)
				if(dep[fa[j][k]]>=dep[z])
					ans[id[i]]=max(ans[id[i]],mx[j][k]),j=fa[j][k];
			j=Y[id[i]];
			for(int k=Mx;~k;--k)
				if(dep[fa[j][k]]>=dep[z])
					ans[id[i]]=max(ans[id[i]],mx[j][k]),j=fa[j][k];
			for(getroot(j=X[id[i]]),j=rt[j];dep[j]>dep[z];)ans[num[j]]=Z[id[i]]-1,getroot(j),getroot(fa[j][0]),j=rt[rt[j]]=rt[fa[j][0]];
			for(getroot(j=Y[id[i]]),j=rt[j];dep[j]>dep[z];)ans[num[j]]=Z[id[i]]-1,getroot(j),getroot(fa[j][0]),j=rt[rt[j]]=rt[fa[j][0]];
		}
	for(int i=1;i<=m;++i)printf("%d ",ans[i]);
	return 0;
}