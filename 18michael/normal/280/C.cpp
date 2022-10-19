#include<cstdio>
int n,edge_t=0;double ans=0;
int la[100002],dep[100002];
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
	ans+=1.0/d;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs(v,x,d+1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	dfs(1,0,1),printf("%.6lf",ans);
	return 0;
}