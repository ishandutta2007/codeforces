#include<bits/stdc++.h>
using namespace std;
int n,t=0,edge_t=1,las=0;
int l[100002],r[100002],p[200002],id[200002],la[200002];
bool pre[200002],ans[100002];
struct aaa
{
	int to,nx;
	bool u;
}edge[400002];
inline bool cmp(int x,int y)
{
	return p[x]<p[y]? 1:0;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x],0},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],0},la[y]=edge_t;
}
inline void dfs(int x)
{
	for(int i=la[x],v;i;i=la[x])
	{
		if(edge[i].u)
		{
			la[x]=edge[i].nx;
			continue;
		}
		v=edge[i].to,edge[i].u=edge[i^1].u=1,la[x]=edge[i].nx,dfs(v);
		if(i<=(n<<1)+1)ans[i>>1]=(i&1);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&l[i],&r[i]),p[id[(i<<1)-1]=(i<<1)-1]=l[i],p[id[i<<1]=(i<<1)]=(++r[i]);
	sort(id+1,id+(n<<1)+1,cmp);
	for(int i=1;i<=(n<<1);++i)(id[i]&1? l[(id[i]+1)>>1]:r[id[i]>>1])=(t+=(i==1 || p[id[i]]!=p[id[i-1]]));
	for(int i=1;i<=n;++i)add_edge(l[i],r[i]),pre[l[i]]^=1,pre[r[i]]^=1;
	for(int i=1;i<=t;++i)
	{
		if((pre[i]^=pre[i-1])&1)if(!las)las=i;else;
		else if(las)add_edge(las,i),las=0;
	}
	for(int i=1;i<=t;++i)if(la[i])dfs(i);
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
	return 0;
}