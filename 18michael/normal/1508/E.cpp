#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,edge_t=0,dfn_t,st_t=0,dfn1_t=0,dfn2_t=0;
LL ans=0;
int a[300002],la[300002],rt[300002],to[300002],dfn[300002],fa[300002],st[300002],dfn1[300002],dfn2[300002],st1[300002],st2[300002],dep[300002],mn[300002],mx[300002],siz[300002];
vector<int> vec[300002];
struct aaa
{
	int to,nx;
}edge[600002];
inline bool cmp(int x,int y)
{
	return dfn[x]<dfn[y];
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
inline void dfs(int x,int f)
{
	fa[x]=f;
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f)dep[v]=dep[x]+1,dfs(v,x),vec[x].push_back(v);
}
inline void dfs1(int x,int f)
{
	siz[x]=1,mn[x]=mx[x]=dfn[x],st1[dfn1[x]=(++dfn1_t)]=x,sort(vec[x].begin(),vec[x].end(),cmp);
	for(int i=0,v;i<vec[x].size();++i)if((v=vec[x][i])!=f)dfs1(v,x);
	st2[dfn2[x]=(++dfn2_t)]=x;
}
int main()
{
	scanf("%d",&n),dfn[1]=dfn_t=1;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),to[a[i]]=rt[i]=i;
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	dfs(1,0);
	for(int i=1,j;i<=n;++i)
	{
		for(j=to[i];(getroot(j),rt[j])!=1;rt[rt[j]]=fa[rt[j]])st[++st_t]=rt[j];
		for(;st_t;--st_t)dfn[st[st_t]]=(++dfn_t);
	}
	dfs1(1,0);
	for(int i=1;i<=n;++i)if(mn[i]<dfn[i] || mx[i]>=dfn[i]+siz[i])return 0&puts("NO");
	for(int i=1;i<=n;ans+=dep[st2[i]],++i)
	{
		if(to[i]==st2[i])continue;
		for(int j=1,x=i-1;j<=n;++j)if(dfn2[st1[j]]>=i)dfn1[st1[j]]=(++x);
		for(int j=to[i];j;j=fa[j])st[++st_t]=j;
		for(;st_t>1;--st_t,++ans)swap(dfn1[st[st_t]],dfn1[st[st_t-1]]);
		for(int j=1;j<=n;++j)if(dfn2[j]>=i && dfn1[j]!=a[j])return 0&puts("NO");
		break;
	}
	printf("YES\n%lld\n",ans);
	for(int i=1;i<=n;++i)printf("%d ",dfn[i]);
	return 0;
}