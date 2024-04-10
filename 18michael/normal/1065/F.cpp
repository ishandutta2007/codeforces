#include<bits/stdc++.h>
#define Mx 19
using namespace std;
int n,k,edge_t=0,rt_t=0,dfn_t=0,st_t=0;
int la[1000002]={},rt[1000002],dfn[1000002],low[1000002],st[1000002],val[1000002]={},dp[1000002];
bool u[1000002]={};
int fa[1000002][22];
typedef pair<int,int> P;
vector<P> vec;
vector<int> son[1000002];
struct aaa
{
	int to,nx;
}edge[2000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
}
inline void dfs(int x)
{
	if(!la[x])
	{
		int y=x;
		for(int i=0,j=k;j;++i,j>>=1)if(j&1)y=fa[y][i];
		vec.push_back(P(x,y)),u[x]=1;
	}
	for(int i=la[x];i;i=edge[i].nx)dfs(edge[i].to);
}
inline void Tarjan(int x)
{
	dfn[x]=low[x]=(++dfn_t),st[++st_t]=x;
	for(int i=la[x],v;i;i=edge[i].nx)
	{
		if(!dfn[v=edge[i].to])Tarjan(v),low[x]=min(low[x],low[v]);
		else if(!rt[v])low[x]=min(low[x],dfn[v]);
	}
	if(low[x]==dfn[x])
	{
		++rt_t;
		do val[rt[st[st_t]]=rt_t]+=u[st[st_t]],--st_t;while(st[st_t+1]!=x);
	}
}
inline void dfs1(int x)
{
	dp[x]=0,u[x]=1;
	for(int i=0,v;i<son[x].size();++i)
		if(!u[v=son[x][i]])
			dfs1(v),dp[x]=max(dp[x],dp[v]);
	dp[x]+=val[x];
}
int main()
{
	read(n),read(k),fa[1][0]=1;
	for(int i=2;i<=n;++i)read(fa[i][0]),add_edge(fa[i][0],i);
	for(int i=1;i<=Mx;++i)for(int j=1;j<=n;++j)fa[j][i]=fa[fa[j][i-1]][i-1];
	dfs(1);for(int i=0;i<vec.size();++i)add_edge(vec[i].first,vec[i].second);
	for(int i=1;i<=n;++i)if(!rt[i])Tarjan(i);
	for(int i=1;i<=rt_t;++i)u[i]=0;
	for(int i=1;i<=n;++i)
		for(int j=la[i];j;j=edge[j].nx)
			son[rt[i]].push_back(rt[edge[j].to]);
	dfs1(rt[1]),printf("%d",dp[rt[1]]);
	return 0;
}