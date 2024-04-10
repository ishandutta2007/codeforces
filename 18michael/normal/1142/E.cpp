#include<bits/stdc++.h>
using namespace std;
int n,m,edge_t=0,dfn_t=0,st_t=0,rt_t=0,now,p,o;
int la[100002],dfn[100002],low[100002],st[100002],rt[100002],deg[100002];
queue<int> q;
vector<int> vec[100002],vec2[100002];
struct aaa
{
	int to,nx;
}edge[100002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
}
inline void Tarjan(int x)
{
	dfn[x]=low[x]=(++dfn_t),st[++st_t]=x;
	for(int i=la[x],v;i;i=edge[i].nx)
	{
		v=edge[i].to;
		if(!dfn[v])Tarjan(v),low[x]=min(low[x],low[v]);
		else if(!rt[v])low[x]=min(low[x],dfn[v]);
	}
	if(dfn[x]==low[x])for(++rt_t;st[st_t+1]^x;--st_t)vec2[rt[st[st_t]]=rt_t].push_back(st[st_t]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	for(int i=1;i<=n;++i)if(!dfn[i])Tarjan(i);
	for(int i=1;i<=n;++i)for(int j=la[i],v;j;j=edge[j].nx)if(rt[i]^rt[v=edge[j].to])vec[rt[i]].push_back(rt[v]),++deg[rt[v]];
	for(int i=1;i<=rt_t;++i)if(!deg[i])q.push(i);
	for(now=q.front(),q.pop();q.size();)
	{
		p=q.front(),q.pop(),printf("? %d %d\n",vec2[now].back(),vec2[p].back()),fflush(stdout),scanf("%d",&o);
		if(!o)swap(now,p);
		vec2[p].pop_back();
		if(vec2[p].size())q.push(p);
		else for(int i=0,v;i<vec[p].size();++i)if(!(--deg[v=vec[p][i]]))q.push(v);
	}
	return 0&printf("! %d",vec2[now].back());
}