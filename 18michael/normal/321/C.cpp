#include<cstdio>
int n,edge_t=0,col_t=0,G;
int la[100002]={},col[100002]={},siz[100002],mx[100002];
char ans[100002];
struct aaa
{
	int to,nx;
}edge[200002];
inline int max(int x,int y)
{
	return x>y? x:y;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int f,int c)
{
	siz[x]=1,mx[x]=0;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f && col[v]==c)
			dfs(v,x,c),siz[x]+=siz[v],mx[x]=max(mx[x],siz[v]);
}
inline void dfs1(int x,int f,int tot,int c)
{
	if((mx[x]=max(mx[x],tot-siz[x]))<mx[G])G=x;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f && col[v]==c)
			dfs1(v,x,tot,c);
}
inline void dfs2(int x,int f,int c,int c1)
{
	col[x]=c1;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f && col[v]==c)
			dfs2(v,x,c,c1);
}
inline void solve(int x,char c)
{
	int g;dfs(x,0,col_t),dfs1(G=x,0,siz[x],col_t),ans[g=G]=c;
	for(int i=la[g],v;i;i=edge[i].nx)
		if(col[v=edge[i].to]==col[g])
			dfs2(v,g,col[v],++col_t),solve(v,c+1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	solve(1,'A');
	for(int i=1;i<=n;++i)printf("%c ",ans[i]);
	return 0;
}