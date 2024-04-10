#include<bits/stdc++.h>
using namespace std;
int n,edge_t=0,st_t=0,ans_t=0;
int la[100002],st[100002],ans[100002];
struct aaa
{
	int to,nx,from;
	bool u;
}edge[100002];
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(aaa){y,la[x],z,0},la[x]=edge_t;
}
inline void dfs(int x)
{
	for(int i=la[x];i;i=edge[i].nx)if(!edge[i].u)edge[i].u=1,dfs(edge[i].to);
	st[++st_t]=x;
}
int main()
{
	scanf("%d",&n);
	if(n&1)return 0&puts("-1");
	for(int i=0;i<n/2;++i)add_edge(((2*2*i)%n)/2,i,2*i),add_edge(((2*(2*i+1))%n)/2,i,2*i+1);
	for(dfs(0);st_t>1;--st_t)
		for(int i=la[st[st_t]];i;i=edge[i].nx)
			if(edge[i].u && edge[i].to==st[st_t-1])
			{
				edge[i].u=0,ans[++ans_t]=edge[i].from;
				break;
			}
	for(;ans_t;--ans_t)printf("%d ",ans[ans_t]);
	return 0&printf("0");
}