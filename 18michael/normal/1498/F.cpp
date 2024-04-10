#include<cstdio>
int n,k,k2,edge_t=0;
int a[100002],la[100002]={},ans[100002]={},G[42];
int F[100002][42]={};
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
	F[x][0]=a[x],d=(d+1==k2? 0:d+1);
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
		{
			dfs(v,x,d);
			for(int j=0;j<k2;++j)F[x][j]^=F[v][j? j-1:k2-1];
		}
}
inline void dfs1(int x,int f)
{
	if(x>1)
	{
		for(int i=0;i<k2;++i)G[i]=(F[f][i]^F[x][i? i-1:k2-1]);
		for(int i=0;i<k2;++i)F[x][i]^=G[i? i-1:k2-1];
	}
	for(int i=k;i<k2;++i)ans[x]^=F[x][i];
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs1(v,x);
}
int main()
{
	scanf("%d%d",&n,&k),k2=(k<<1);
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);dfs(1,0,0),dfs1(1,0);
	for(int i=1;i<=n;++i)printf("%d%c",(ans[i]>0),i==n? '\n':' ');
	return 0;
}