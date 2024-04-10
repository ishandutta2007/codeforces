#include<cstdio>
int n,edge_t=0;
int a[100002],b[100002],la[200002]={},col[200002]={};
struct aaa
{
	int to,nx;
}edge[400002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int c)
{
	col[x]=c;
	for(int i=la[x],v;i;i=edge[i].nx)if(!col[v=edge[i].to])dfs(v,-c);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&a[i],&b[i]),add_edge(a[i],b[i]),add_edge(2*i-1,2*i);
	for(int i=1;i<=(n<<1);++i)if(!col[i])dfs(i,1);
	for(int i=1;i<=n;++i)printf("%d %d\n",1+(col[a[i]]==1),1+(col[b[i]]==1));
	return 0;
}