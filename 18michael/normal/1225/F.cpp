#include<cstdio>
int n,mx=0,edge_t=0,a_t=0;bool ok=0;
int p[100002],la[100002]={},dep[100002],son[100002],a[100002],fa[100002];
struct aaa
{
	int to,nx;
}edge[100002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int max(int a,int b)
{
	return a>b? a:b;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
}
inline void dfs(int x,int d)
{
	int v;dep[x]=d,mx=max(mx,dep[x]);
	for(int i=la[x];i;i=edge[i].nx)dfs(edge[i].to,d+1);
}
inline void dfs1(int x)
{
	if(dep[x]==mx){ok=1;return ;}
	for(int i=la[x],v;i;i=edge[i].nx)
	{
		v=edge[i].to,dfs1(v);
		if(ok){son[x]=v;return ;}
	}
}
inline void dfs2(int x)
{
	a[++a_t]=x;
	for(int i=la[x],v;i;i=edge[i].nx)
	{
		v=edge[i].to;
		if(v!=son[x])dfs2(v);
	}
	if(son[x]!=-1)dfs2(son[x]);
}
int main()
{
	read(n),p[0]=-1;
	for(int i=1;i<n;++i)read(p[i]),add_edge(p[i],i),son[i]=-1;
	dfs(0,1),dfs1(0),dfs2(0),a[0]=-1;
	for(int i=1;i<=a_t;++i)printf("%d%c",a[i],i==a_t? '\n':' '),fa[a[i]]=a[i-1];
	printf("%d\n",n-mx);
	for(int i=1;i<=a_t;++i)
		while(fa[a[i]]!=p[a[i]])
			printf("%d ",a[i]),fa[a[i]]=fa[fa[a[i]]];
	return 0;
}