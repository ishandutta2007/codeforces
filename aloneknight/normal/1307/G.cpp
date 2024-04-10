#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,Q,cc=1,tt,hd[N],vis[N],d[N],pre[N],id[N],w[N];
struct E{int v,nxt,w,c;}e[N*2]; 
inline void add(int u,int v,int w,int c)
{
	e[++cc]=(E){v,hd[u],w,c};hd[u]=cc;
	e[++cc]=(E){u,hd[v],0,-c};hd[v]=cc;
}
inline bool spfa()
{
	for(int i=1;i<=n;i++)d[i]=1e9,vis[i]=0;
	queue<int>q;q.push(1);d[1]=0;
	while(!q.empty())
	{
		int x=q.front();q.pop();vis[x]=0;
		for(int i=hd[x],y;i;i=e[i].nxt)if(e[i].w&&d[y=e[i].v]>d[x]+e[i].c)
		{
			d[y]=d[x]+e[i].c;pre[y]=i;//id[y]=i;
			if(!vis[y])vis[y]=1,q.push(y);
		}
	}
	if(d[n]==1e9)return 0;
	tt++;w[tt]=w[tt-1]+d[n];
	for(int i=pre[n];i;i=pre[e[i^1].v])e[i].w--,e[i^1].w++;
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=m;i++)scanf("%d%d%d",&u,&v,&w),add(u,v,1,w);
	while(spfa());scanf("%d",&Q);
	while(Q--)
	{
		int x;scanf("%d",&x);double ans=1e9;
		for(int i=1;i<=tt;i++)ans=min(ans,1.0*(w[i]+x)/i);
		printf("%.10lf\n",ans);
	}
	return 0;
}