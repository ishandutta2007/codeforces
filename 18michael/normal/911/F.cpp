#include<cstdio>
#define LL long long
int n,mx,ans,ans1,edge_t=0,q_t=0,head=1;
LL res=0;
bool ok=0;
int la[200002]={},q[200002],dis[200002],dis1[200002];
bool vis[200002]={},u[200002]={};
struct aaa
{
	int to,nx;
}edge[400002];
inline int max(int a,int b)
{
	return a>b? a:b;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int f,int d)
{
	if((dis[x]=d)>mx)mx=d,ans=x;
	for(int i=la[x];i;i=edge[i].nx)
		if(edge[i].to!=f)
			dfs(edge[i].to,x,d+1);
}
inline void dfs1(int x,int f,int d)
{
	dis1[x]=d;
	for(int i=la[x];i;i=edge[i].nx)
		if(edge[i].to!=f)
			dfs1(edge[i].to,x,d+1);
}
inline void dfs2(int x,int f,int d)
{
	if(d==mx){vis[q[++q_t]=ans1=x]=u[x]=ok=1,++res;return ;}
	for(int i=la[x];i;i=edge[i].nx)
		if(edge[i].to!=f)
		{
			dfs2(edge[i].to,x,d+1);
			if(ok){vis[q[++q_t]=x]=u[x]=1,++res;return ;}
		}
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	dfs(ans=1,0,mx=0),dfs(ans,0,mx=0),dfs1(ans,0,0),dfs2(ans,0,0),res=((res*(res-1))>>1);
	while(head<=q_t)
	{
		for(int i=la[q[head]],v;i;i=edge[i].nx)
			if(!u[v=edge[i].to])
				u[q[++q_t]=v]=1,res+=max(dis[v],dis1[v]);
		++head;
	}
	printf("%lld\n",res);
	for(int i=n;i>1;--i)printf("%d %d %d\n",q[i],(vis[q[i]] || dis[q[i]]>dis1[q[i]])? ans1:ans,q[i]);
	return 0;
}