#include<bits/stdc++.h>
using namespace std;
int n,m,edge_t=1,las=0;
bool o=0;
int la[100002],deg[100002];
struct aaa
{
	int to,nx;
	bool u;
}edge[500002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x],0},la[x]=edge_t,++deg[x];
	edge[++edge_t]=(aaa){x,la[y],0},la[y]=edge_t,++deg[y];
}
inline void dfs(int x)
{
	for(int i=la[x],v;i;i=la[x])
	{
		v=edge[i].to,la[x]=edge[i].nx;
		if(!edge[i].u)edge[i].u=edge[i^1].u=1,dfs(v),printf("%d %d\n",o? x:v,o? v:x),o^=1;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	for(int i=1;i<=n;++i)
		if(deg[i]&1)
		{
			if(!las)las=i;
			else add_edge(las,i),las=0;
		}
	printf("%d\n",(edge_t+((edge_t/2)&1))/2);
	if((edge_t/2)&1)puts("1 1");
	return dfs(1),0;
}