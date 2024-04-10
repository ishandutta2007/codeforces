#include<bits/stdc++.h>
#define Mx 16
#define eps 1e-10
#define inf 0x3f3f3f3f
#define ld long double
using namespace std;
int n,m,edge_t=0,dfn_t=0;
ld ans=inf,T;
int la[100002],siz[100002],son[100002],top[100002],dfn[100002],dep[100002];
int fa[100002][18];
struct aaa
{
	int to,nx;
}edge[200002];
struct bbb
{
	ld t;
	int v,u,c;
	bool o;
};
vector<bbb> vec[100002];
struct ccc
{
	ld t;
	int v,u,c;
	inline bool operator < (const ccc &a) const
	{
		return v+(T-t)*c<a.v+(T-a.t)*a.c;
	}
};
multiset<ccc> s;
multiset<ccc>::iterator it;
inline bool cmp(bbb a,bbb b)
{
	return fabs(a.t-b.t)<eps? (a.o>b.o):(a.t<b.t);
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int f,int d)
{
	siz[x]=1,dep[x]=d,fa[x][0]=f;
	for(int i=1;i<=Mx;++i)fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
		{
			dfs(v,x,d+1),siz[x]+=siz[v];
			if(siz[v]>siz[son[x]])son[x]=v;
		}
}
inline void dfs1(int x,int f,int t)
{
	dfn[x]=(++dfn_t),top[x]=t;
	if(son[x])dfs1(son[x],x,t);
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f && v!=son[x])
			dfs1(v,x,v);
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=Mx;~i;--i)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	if(x==y)return x;
	for(int i=Mx;~i;--i)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
inline void ins(int x,ld t,int v,int u,int c)
{
	vec[x].push_back((bbb){t,v,u,v<u? c:-c,1}),vec[x].push_back((bbb){t+1.0*abs(v-u)/c,v,u,v<u? c:-c,0});
}
inline void calc(ccc a,ccc b)
{
	if(a.c==b.c)
	{
		if(a.v==b.v+(a.t-b.t)*b.c && b.v+(a.t-b.t)*b.c>=min(b.v,b.u)-eps && b.v+(a.t-b.t)*b.c<=max(b.v,b.u)+eps)ans=min(ans,a.t);
		return ;
	}
	ld X=(b.v+(a.t-b.t)*b.c-a.v)/(a.c-b.c);
	if((a.v+a.c*X>=min(a.v,a.u)-eps && a.v+a.c*X<=max(a.v,a.u)+eps) && (b.v+(a.t-b.t)*b.c+b.c*X>=min(b.v,b.u)-eps && b.v+(a.t-b.t)*b.c+b.c*X<=max(b.v,b.u)+eps))ans=min(ans,a.t+X);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	dfs(1,0,1),dfs1(1,0,1);
	for(int i=1,t,c,v,u,w,d,o;i<=m;++i)
	{
		scanf("%d%d%d%d",&t,&c,&v,&u),w=LCA(v,u),d=dep[v],o=0;
		for(;dep[fa[top[v]][0]]>=dep[w];v=fa[top[v]][0])ins(top[v],t+1.0*(d-dep[v])/c,dep[v],dep[fa[top[v]][0]],c);
		for(;dep[fa[top[u]][0]]>=dep[w];u=fa[top[u]][0])ins(top[u],t+1.0*(d-dep[w]+dep[fa[top[u]][0]]-dep[w])/c,dep[fa[top[u]][0]],dep[u],c);
		if(v!=w)ins(top[v],t+1.0*(d-dep[v])/c,dep[v],dep[w],c);else o=1;
		if(u!=w || o)ins(top[u],t+1.0*(d-dep[w])/c,dep[w],dep[u],c);
	}
	for(int i=1;i<=n;++i)
	{
		s.clear(),sort(vec[i].begin(),vec[i].end(),cmp);
		for(int j=0;j<vec[i].size();++j)
		{
			if((T=vec[i][j].t)>=ans)break;
			if(vec[i][j].o)
			{
				it=s.lower_bound((ccc){vec[i][j].t,vec[i][j].v,vec[i][j].u,vec[i][j].c});
				if(it!=s.end())calc((ccc){vec[i][j].t,vec[i][j].v,vec[i][j].u,vec[i][j].c},*it);
				if(it!=s.begin())calc((ccc){vec[i][j].t,vec[i][j].v,vec[i][j].u,vec[i][j].c},*(--it));
				s.insert((ccc){vec[i][j].t,vec[i][j].v,vec[i][j].u,vec[i][j].c});
			}
			else s.erase((ccc){vec[i][j].t-1.0*(vec[i][j].u-vec[i][j].v)/vec[i][j].c,vec[i][j].v,vec[i][j].u,vec[i][j].c});
		}
	}
	if(abs(ans-inf)<eps)puts("-1");
	else printf("%.10Lf",ans);
	return 0;
}