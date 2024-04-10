#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int t,T,n,m,n1=inf,n2=-inf,edge_t;
int l[100002],r[100002],X[100002],Y[100002],la[100012],col[100012];
struct aaa
{
	int to,nx;
}edge[1200012];
inline bool in(int x,int y,int z)
{
	return x>=y && x<=z;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline bool dfs(int x,int c)
{
	col[x]=c;
	for(int i=la[x],v;i;i=edge[i].nx)if((!col[v=edge[i].to] && !dfs(v,-c)) || (col[v] && col[v]!=-c))return 0;
	return 1;
}
inline bool solve(int n1,int n2)
{
	if(n1<0 || n2<0)return 0;
	edge_t=0;
	for(int i=1;i<=n+2;++i)la[i]=col[i]=0;
	add_edge(n+1,n+2);
	for(int i=1;i<=n;++i)
	{
		if(!in(n1,l[i],r[i]))add_edge(i,n+1);
		if(!in(n2,l[i],r[i]))add_edge(i,n+2);
	}
	for(int i=1;i<=m;++i)add_edge(X[i],Y[i]);
	if(!dfs(n+1,-1))return 0;
	for(int i=1;i<=n;++i)if(!col[i] && !dfs(i,1))return 0;
	printf("POSSIBLE\n%d %d\n",n1,n2);
	for(int i=1;i<=n;++i)printf("%d",1+(col[i]==1));
	return 1;
}
int main()
{
	scanf("%d%d%d%d",&t,&T,&n,&m);
	for(int i=1;i<=n;++i)scanf("%d%d",&l[i],&r[i]),n1=min(n1,r[i]),n2=max(n2,l[i]);
	for(int i=1;i<=m;++i)scanf("%d%d",&X[i],&Y[i]);
	if(!(in(n1+n2,t,T) && solve(n1,n2)) && !(!in(n1+n2,t,T) && ((n1+n2>T && solve(T-n2,n2)) || (n1+n2<t && solve(n1,t-n1)))))puts("IMPOSSIBLE");
	return 0;
}