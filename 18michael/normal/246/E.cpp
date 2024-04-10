#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,m2,edge_t=0,num_t=0,dfn_t=0;
int num[100002],la[100002]={},ans[100002]={},pos[100002]={},fa[100002],dep[100002],dfn[100002],id[100002],siz[100002];
string s;
map<string,int> mp;
struct aaa
{
	int to,nx;
}edge[100002];
struct bbb
{
	int x,l,r,o,id;
}qry[200002];
inline int lowbit(int x)
{
	return x&(-x);
}
struct BIT
{
	int sum[100002];
	inline void modify(int x,int d)
	{
		while(x<=n)sum[x]+=d,x+=lowbit(x);
	}
	inline int query(int x)
	{
		int res=0;
		while(x)res+=sum[x],x-=lowbit(x);
		return res;
	}
}S;
inline bool cmp(int x,int y)
{
	return (dep[x]==dep[y])? (dfn[x]<dfn[y]):(dep[x]<dep[y]);
}
inline bool cmp1(bbb a,bbb b)
{
	return a.x<b.x? 1:0;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
}
inline void dfs(int x,int d)
{
	dfn[x]=(++dfn_t),dep[x]=d,siz[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)dfs(v=edge[i].to,d+1),siz[x]+=siz[v];
}
inline int findL(int d,int x)
{
	int l=1,r=n,mid;
	while(l<=r)
	{
		mid=((l+r)>>1);
		if(dep[id[mid]]>d || (dep[id[mid]]==d && dfn[id[mid]]>=x))r=mid-1;
		else l=mid+1;
	}
	return l;
}
inline int findR(int d,int x)
{
	int l=1,r=n,mid;
	while(l<=r)
	{
		mid=((l+r)>>1);
		if(dep[id[mid]]<d || (dep[id[mid]]==d && dfn[id[mid]]<=x))l=mid+1;
		else r=mid-1;
	}
	return r;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		cin>>s,scanf("%d",&fa[i]),id[i]=i;
		if(!mp.count(s))mp[s]=(++num_t);
		num[i]=mp[s];if(fa[i])add_edge(fa[i],i);
	}
	for(int i=1;i<=n;++i)if(!fa[i])dfs(i,1);
	sort(id+1,id+n+1,cmp),scanf("%d",&m),m2=(m<<1);
	for(int i=1,x,y,l,r;i<=m;++i)scanf("%d%d",&x,&y),l=findL(dep[x]+y,dfn[x]),r=findR(dep[x]+y,dfn[x]+siz[x]-1),qry[2*i-1]=(bbb){l-1,l,r,-1,i},qry[2*i]=(bbb){r,l,r,1,i};
	sort(qry+1,qry+m2+1,cmp1);
	for(int i=1,j=1;i<=m2;++i)
	{
		while(j<=qry[i].x)
		{
			if(pos[num[id[j]]])S.modify(pos[num[id[j]]],-1);
			S.modify(pos[num[id[j]]]=j,1),++j;
		}
		ans[qry[i].id]+=qry[i].o*(S.query(qry[i].r)-S.query(qry[i].l-1));
	}
	for(int i=1;i<=m;++i)printf("%d\n",ans[i]);
	return 0;
}