#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,edge_t=0;
LL las,sum=0;
int c[400002],to[400002],cnt[400002],la[400002],fa[400002],siz[400002],siz2[400002];
LL ans[400002],pwsiz[400002],pwsiz2[400002];
int son[400002][2];
vector<int> Vec;
typedef pair<int,int> P;
vector<P> vec[400002];
struct aaa
{
	int to,nx;
}edge[800002];
inline LL pw(LL x)
{
	return x*x;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int f)
{
	to[x]=f;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs(v,x);
}
inline bool IsRoot(int x)
{
	return (!x || (x!=son[fa[x]][0] && x!=son[fa[x]][1]));
}
inline bool Get(int x)
{
	return x==son[fa[x]][1];
}
inline void PushUp(int x)
{
	if(x)siz[x]=siz[son[x][0]]+siz[son[x][1]]+siz2[x]+(x<=n),pwsiz[x]=pw(siz[son[x][0]])+pw(siz[son[x][1]])+pwsiz2[x];
}
inline void Rotate(int x)
{
	int y=fa[x],w=fa[y],gx=Get(x),gy=Get(y),z=son[x][gx^1];
	if(!IsRoot(y))son[w][gy]=x;
	fa[x]=w,fa[y]=x,son[x][gx^1]=y,fa[z]=y,son[y][gx]=z,PushUp(y),PushUp(x);
}
inline void Splay(int x)
{
	for(;!IsRoot(x);Rotate(x))if(!IsRoot(fa[x]))Rotate(Get(x)==Get(fa[x])? fa[x]:x);
}
inline int Access(int x)
{
	int p;
	for(p=0;x;p=x,x=fa[x])Splay(x),siz2[x]+=siz[son[x][1]]-siz[p],pwsiz2[x]+=pw(siz[son[x][1]])-pw(siz[p]),son[x][1]=p,PushUp(x);
	return p;
}
inline int FindRoot(int x)
{
	for(x=Access(x);;x=son[x][0])
		if(!son[x][0])
		{
			Splay(x);
			return x;
		}
}
inline void Link(int x,int y)
{
	sum-=pwsiz[FindRoot(x)]+pwsiz[FindRoot(y)],Access(x),Splay(x),Access(y),Splay(y),fa[y]=x,pwsiz2[x]+=pw(siz[y]),siz2[x]+=siz[y],PushUp(x),sum+=pwsiz[FindRoot(x)];
}
inline void Cut(int x,int y)
{
	sum-=pwsiz[FindRoot(x)],Access(y),Splay(x),Splay(y),son[y][0]=fa[x]=0,PushUp(y),sum+=pwsiz[FindRoot(x)]+pwsiz[FindRoot(y)];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&c[i]),vec[c[i]].push_back(P(i,0));
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	dfs(1,n+1);
	for(int i=1;i<=n;++i)Link(to[i],i);
	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),vec[c[x]].push_back(P(x,i)),vec[c[x]=y].push_back(P(x,i));
	for(int i=1;i<=n;++i)
	{
		las=sum;
		for(int j=0;j<vec[i].size();++j)
		{
			if(!cnt[vec[i][j].first])Vec.push_back(vec[i][j].first);
			if((++cnt[vec[i][j].first])&1)Cut(to[vec[i][j].first],vec[i][j].first);
			else Link(to[vec[i][j].first],vec[i][j].first);
			ans[vec[i][j].second]-=sum-las,las=sum;
		}
		for(;!Vec.empty();cnt[Vec.back()]=0,Vec.pop_back())if(cnt[Vec.back()]&1)Link(to[Vec.back()],Vec.back());
	}
	for(int i=1;i<=m;++i)ans[i]+=ans[i-1];
	for(int i=0;i<=m;++i)printf("%lld\n",ans[i]);
	return 0;
}