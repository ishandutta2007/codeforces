#include<bits/stdc++.h>
using namespace std;
int n,edge_t=0;
int la[200002]={},cnt[2]={};
struct aaa
{
	int to,nx;
}edge[400002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int f,int c)
{
	++cnt[c];
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs(v,x,(c^1));
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	dfs(1,0,0),printf("%d",max(min(cnt[0],cnt[1])-1,0));
	return 0;
}