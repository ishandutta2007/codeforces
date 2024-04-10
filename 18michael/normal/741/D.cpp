#include<cstdio>
#define inf 0x3f3f3f3f
int n,edge_t=0;
char ch[500002];
int la[500002]={},siz[500002],son[500002],ans[500002]={},dep[500002];
struct aaa
{
	int to,nx;
	char c;
}edge[500002];
inline int max(int x,int y)
{
	return x>y? x:y;
}
inline void swap(int &x,int &y)
{
	int z=x;x=y,y=z;
}
struct bbb
{
	int vec_t,laz,laz1;
	int mx[4194304],vec[4194304];
	inline void init()
	{
		vec_t=laz=0;
		for(int i=0;i<4194304;++i)mx[i]=-inf;
	}
	inline void clear()
	{
		while(vec_t)mx[vec[vec_t]]=-inf,--vec_t;
		laz=laz1=0;
	}
	inline void ins(int x,int y)
	{
		if(mx[x^=laz]==-inf)vec[++vec_t]=x;
		mx[x]=max(mx[x],y-laz1);
	}
}A[2];
inline void add_edge(int x,int y,char c)
{
	edge[++edge_t]=(aaa){y,la[x],c},la[x]=edge_t;
}
inline void dfs(int x)
{
	siz[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)
	{
		dfs(v=edge[i].to),siz[x]+=siz[v];
		if(siz[v]>siz[son[x]])son[x]=v;
	}
}
inline void merge()
{
	while(A[1].vec_t)A[0].ins(A[1].vec[A[1].vec_t],A[1].mx[A[1].vec[A[1].vec_t]]),A[1].mx[A[1].vec[A[1].vec_t]]=-inf,--A[1].vec_t;
}
inline void check(int x,int y,int z)
{
	z+=A[0].laz1;if(A[0].mx[y^=A[0].laz]>-inf)ans[x]=max(ans[x],A[0].mx[y]+z);
	for(int i=1;i<4194304;i<<=1)if(A[0].mx[y^i]>-inf)ans[x]=max(ans[x],A[0].mx[y^i]+z);
}
inline void dfs1(int x,int y,int z)
{
	check(y,z,dep[x]-dep[y]);
	if(x==y)for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=son[x])
			A[0].clear(),dfs1(v,v,0),ans[x]=max(ans[x],ans[v]);
	if(son[x])
	{
		if(x==y)A[0].clear(),dfs1(son[x],son[x],0),ans[x]=max(ans[x],ans[son[x]]),A[0].laz^=(1<<(ch[son[x]]-'a')),++A[0].laz1,A[0].ins(0,0),check(x,0,0);
		else dfs1(son[x],y,z^(1<<(ch[son[x]]-'a')));
	}
	else if(x==y)A[0].ins(0,0);
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=son[x])
		{
			if(x==y)A[1].clear();
			dfs1(v,y,z^(1<<(edge[i].c-'a')));
			if(x==y)merge();
		}
	if(x!=y)A[1].ins(z,dep[x]-dep[y]);
}
int main()
{
	A[0].init(),A[1].init(),dep[1]=1,scanf("%d",&n);
	for(int i=2,x;i<=n;++i)
	{
		scanf("%d",&x),dep[i]=dep[x]+1;
		do ch[i]=getchar();while(ch[i]<'a' || ch[i]>'v');
		add_edge(x,i,ch[i]);
	}
	dfs(1),dfs1(1,1,0);
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
	return 0;
}