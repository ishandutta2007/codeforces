#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,edge_t=0,dfn_t=0,st_t=0;
int la[100002],rt[100002],dfn[100002],siz[100002],cnt[100002],cnt2[100002],st[100002],dep[100002];
typedef pair<int,int> P;
vector<P> vec;
vector<int> Vec[100002];
struct aaa
{
	int to,nx;
	bool u;
}edge[400002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void add_edge(int x,int y,bool z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],z},la[y]=edge_t;
}
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
inline void dfs(int x,int f)
{
	dfn[x]=(++dfn_t),siz[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)if(edge[i].u && (v=edge[i].to)!=f)dfs(v,x),siz[x]+=siz[v];
}
inline void dfs1(int x,int f)
{
	st[dep[x]=(++st_t)]=x;
	for(int i=0,v;i<Vec[x].size();++i)--cnt[dfn[v=st[dep[Vec[x][i]]+1]]],++cnt[dfn[v]+siz[v]];
	for(int i=la[x],v;i;i=edge[i].nx)if(edge[i].u && (v=edge[i].to)!=f)dfs1(v,x);
	--st_t;
}
int main()
{
	read(n),read(m);
	for(int i=1;i<=n;++i)rt[i]=i;
	for(int i=1,x,y;i<=m;++i)
	{
		scanf("%d%d",&x,&y),getroot(x),getroot(y),add_edge(x,y,rt[x]!=rt[y]);
		if(rt[x]!=rt[y])rt[rt[x]]=rt[y];
		else vec.push_back(P(x,y));
	}
	dfs(1,0);
	for(int i=0,x,y;i<vec.size();++i)
	{
		if(dfn[x=vec[i].first]>dfn[y=vec[i].second])swap(x,y);
		++cnt[dfn[y]],--cnt[dfn[y]+siz[y]];
		if(dfn[y]<dfn[x]+siz[x])++cnt[1],Vec[y].push_back(x);
		else ++cnt[dfn[x]],--cnt[dfn[x]+siz[x]];
	}
	dfs1(1,0);
	for(int i=2;i<=n;++i)cnt[i]+=cnt[i-1];
	for(int i=1;i<=n;++i)printf("%d",cnt[dfn[i]]==vec.size());
	return 0;
}