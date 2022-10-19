#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,S=0,T,edge_t=1,p;
LL ans=0;
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1},la[2002],dis[2002],cur[2002];
typedef pair<int,int> P;
map<P,int> mp;
map<P,int>::iterator it;
queue<int> q;
struct aaa
{
	int to,nx;
	LL f;
}edge[8002];
inline void add_edge(int x,int y,LL z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],0},la[y]=edge_t;
}
inline bool bfs()
{
	for(int i=0;i<=T;++i)dis[i]=-1,cur[i]=la[i];
	for(q.push(dis[S]=0);q.size();)
	{
		p=q.front(),q.pop();
		for(int i=la[p],v;i;i=edge[i].nx)if(edge[i].f && !(~dis[v=edge[i].to]))dis[v]=dis[p]+1,q.push(v);
	}
	return ~dis[T];
}
inline LL dfs(int x,LL f)
{
	if(x==T)return f;
	LL used=0,tmp;
	for(int &i=cur[x],v;i;i=edge[i].nx)
		if(edge[i].f && dis[v=edge[i].to]==dis[x]+1)
		{
			tmp=dfs(v,min(f-used,edge[i].f)),edge[i].f-=tmp,edge[i^1].f+=tmp;
			if((used+=tmp)==f)break;
		}
	if(!used)dis[x]=0;
	return used;
}
inline LL Dinic()
{
	LL maxflow=0;
	while(bfs())maxflow+=dfs(S,inf);
	return maxflow;
}
int main()
{
	scanf("%d",&n),T=(n<<1)+1;
	for(int i=1,x,y,z;i<=n;++i)
	{
		scanf("%d%d%d",&x,&y,&z),mp[P(x,y)]=i,add_edge(i,i+n,z),ans+=z;
		if((x&1) && !(y&1))add_edge(S,i,inf);
		if((x&1) && (y&1))add_edge(i+n,T,inf);
	}
	for(it=mp.begin();it!=mp.end();++it)
	{
		int x,y,nx,ny;
		x=(*it).first.first,y=(*it).first.second;
		if((x^y)&1)for(int i=0;i<4;i+=2)if(mp.count(P(nx=(*it).first.first+dx[i],ny=(*it).first.second+dy[i])))add_edge((*it).second+n,mp[P(nx,ny)],inf);
		if(!(x&1) && !(y&1))for(int i=1;i<4;i+=2)if(mp.count(P(nx=(*it).first.first+dx[i],ny=(*it).first.second+dy[i])))add_edge((*it).second+n,mp[P(nx,ny)],inf);
	}
	return 0&printf("%lld",ans-Dinic());
}