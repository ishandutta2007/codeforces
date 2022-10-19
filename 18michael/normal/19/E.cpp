#include<cstdio>
int n,m,edge_t=1,cnt=0,vec_t=0;
int la[10002]={},dep[10002]={},A[10002]={},B[10002]={},eA[10002]={},eB[10002]={},vec[10002];
bool u[10002]={};
struct aaa
{
	int to,nx;
}edge[20002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int d)
{
	dep[x]=d;
	for(int i=la[x],v;i;i=edge[i].nx)
		if(!u[i>>1])
		{
			u[i>>1]=1;
			if(!dep[v=edge[i].to])dfs(v,d+1),eA[i>>1]+=A[v],eB[i>>1]+=B[v],A[x]+=A[v],B[x]+=B[v];
			else if((d-dep[v]+1)&1)--A[v],++A[x],++eA[i>>1],++cnt;
			else --B[v],++B[x],++eB[i>>1];
		}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	for(int i=1;i<=n;++i)if(!dep[i])dfs(i,1);
	for(int i=1;i<=m;++i)if(!cnt || (!eB[i] && eA[i]==cnt))vec[++vec_t]=i;
	printf("%d\n",vec_t);
	for(int i=1;i<=vec_t;++i)printf("%d ",vec[i]);
	return 0;
}