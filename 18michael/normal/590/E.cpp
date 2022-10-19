#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,S=0,T,edge_t=1,l,now,to_t=0,t=0;
int la[1502],dis[1502],num[10000002],pos[752],fail[10000002],fa[10000002],id[752];
int to[10000002][2];
vector<int> vec[752];
bool vis[1502];
bitset<752> u[752];
queue<int> q;
char s[10000002];
struct aaa
{
	int to,nx,f;
}edge[600002];
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],0},la[y]=edge_t;
}
inline bool bfs()
{
	for(int i=1;i<=T;++i)dis[i]=inf;
	int p;
	for(q.push(dis[0]=0);q.size();)
	{
		p=q.front(),q.pop();
		for(int i=la[p],v;i;i=edge[i].nx)
			if(edge[i].f && dis[v=edge[i].to]==inf)
				dis[v]=dis[p]+1,q.push(v);
	}
	return dis[T]<inf;
}
inline int dfs(int x,int f)
{
	if(x==T)return f;
	int tmp,used=0;
	for(int i=la[x],v;i;i=edge[i].nx)
		if(edge[i].f && dis[v=edge[i].to]==dis[x]+1)
		{
			tmp=dfs(v,min(edge[i].f,f-used)),edge[i].f-=tmp,edge[i^1].f+=tmp;
			if((used+=tmp)==f)break;
		}
	if(!used)dis[x]=inf;
	return used;
}
inline int Dinic()
{
	int maxflow=0;
	while(bfs())maxflow+=dfs(S,inf);
	return maxflow;
}
inline void dfs1(int x)
{
	vis[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to) && v<T && !vis[v] && !edge[i].f)dfs1(v);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1),l=strlen(s+1),now=0;
		for(int j=1;j<=l;++j)
		{
			if(!to[now][s[j]-='a'])fa[to[now][s[j]]=(++to_t)]=now;
			now=to[now][s[j]];
		}
		if(num[now])continue;
		id[++t]=i,num[pos[t]=now]=t,now=0;
		for(int j=1;j<=l;++j)vec[t].push_back(now=to[now][s[j]]);
	}
	T=(t<<1)+1;
	for(int i=0;i<2;++i)if(to[0][i])for(int j=0;j<2;++j)if(to[to[0][i]][j])q.push(to[to[0][i]][j]);
	for(int p,c;q.size();)
	{
		for(p=q.front(),q.pop(),c=(to[fa[p]][1]==p),now=fail[fa[p]];now && !to[now][c];now=fail[now]);
		fail[p]=to[now][c];
		for(int i=0;i<2;++i)if(to[p][i])q.push(to[p][i]);
	}
	for(int i=1;i<=t;++i)
		for(int j=0;j<vec[i].size();++j)
		{
			for(now=(j+1==vec[i].size()? fail[vec[i][j]]:vec[i][j]);now && !num[now];now=fail[now]);
			if(num[now])u[i][num[now]]=1;
			for(int k=vec[i][j],x;k!=now;k=x)x=fail[k],fail[k]=now;
		}
	for(int i=1;i<=t;++i)for(int j=1;j<=t;++j)if(u[j].test(i))u[j]|=u[i];
	for(int i=1;i<=t;++i)
	{
		add_edge(S,i,1),add_edge(i+t,T,1);
		for(int j=1;j<=t;++j)if(u[i].test(j))add_edge(i,j+t,1);
	}
	printf("%d\n",t-Dinic());
	for(int i=la[T],v;i;i=edge[i].nx)if(!edge[i].f && !vis[v=edge[i].to])dfs1(v);
	for(int i=1;i<=t;++i)if(!vis[i] && vis[i+t])printf("%d ",id[i]);
	return 0;
}