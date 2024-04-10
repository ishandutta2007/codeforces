#include<cstdio>
#include<vector>
using namespace std;
int n,m,edge_t=0;
int la[500002]={},siz[500002],son[500002],dep[500002];
bool ans[500002];
char s[500002];
typedef pair<int,int> P;P p;
vector<P> vec[500002];
struct aaa
{
	int to,nx;
}edge[1000002];
struct bbb
{
	int mnd,mxd;
	int a[500002];
	inline void init()
	{
		mnd=0,mxd=-1;
		for(int i=1;i<=n;++i)a[i]=0;
	}
	inline void clear()
	{
		while(mxd>=mnd)a[mxd]=0,--mxd;
	}
	inline void ins(int x,int y)
	{
		if(mnd>mxd)mnd=mxd=x;
		else mnd=min(mnd,x),mxd=max(mxd,x);
		a[x]^=(1<<y);
	}
}A[2];
inline int lowbit(int x)
{
	return x&(-x);
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int f,int d)
{
	siz[x]=1,dep[x]=d;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
		{
			dfs(v,x,d+1),siz[x]+=siz[v];
			if(siz[v]>siz[son[x]])son[x]=v;
		}
}
inline void merge()
{
	A[0].mnd=min(A[0].mnd,A[1].mnd),A[0].mxd=max(A[0].mxd,A[1].mxd);
	while(A[1].mxd>=A[1].mnd)A[0].a[A[1].mxd]^=A[1].a[A[1].mxd],A[1].a[A[1].mxd]=0,--A[1].mxd;
}
inline void dfs1(int x,int f,int y)
{
	if(x==y)for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f && v!=son[x])
			A[0].clear(),dfs1(v,x,v);
	if(son[x])
	{
		if(x==y)A[0].clear(),dfs1(son[x],x,son[x]);
		else dfs1(son[x],x,y);
	}
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f && v!=son[x])
		{
			if(x==y)A[1].clear();
			dfs1(v,x,y);
			if(x==y)merge();
		}
	if(x==y)
	{
		A[0].ins(dep[x],s[x]-'a');
		for(int i=0;i<vec[x].size();++i)ans[vec[x][i].second]=(vec[x][i].first<A[0].mnd || vec[x][i].first>A[0].mxd || lowbit(A[0].a[vec[x][i].first])==A[0].a[vec[x][i].first]);
	}
	else A[1].ins(dep[x],s[x]-'a');
}
int main()
{
	scanf("%d%d",&n,&m),A[0].init(),A[1].init();
	for(int i=2,x;i<=n;++i)scanf("%d",&x),add_edge(i,x);
	scanf("%s",s+1);
	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),vec[x].push_back(P(y,i));
	dfs(1,0,1),dfs1(1,0,1);
	for(int i=1;i<=m;++i)puts(ans[i]? "Yes":"No");
	return 0;
}