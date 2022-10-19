#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,l,w,edge_t=0,col_t=0,G,tot;LL ans=0;
int la[100002]={},col[100002]={},siz[100002],mx[100002];
typedef pair<int,int> P;
vector<P> vec;
struct aaa
{
	int to,nx,val;
}edge[200002];
inline int lowbit(int x)
{
	return x&(-x);
}
struct BIT
{
	int sum[100002];
	inline void modify(int x,int d)
	{
		for(++x;x<=n;x+=lowbit(x))sum[x]+=d;
	}
	inline int query(int x)
	{
		int res=0;
		for(++x;x>0;x-=lowbit(x))res+=sum[x];
		return res;
	}
}S;
inline bool cmp(P a,P b)
{
	return a.second<b.second? 1:0;
}
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],z},la[y]=edge_t;
}
inline void dfs(int x,int f,int c)
{
	siz[x]=1,mx[x]=0;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f && col[v]==c)
			dfs(v,x,c),siz[x]+=siz[v],mx[x]=max(mx[x],siz[v]);
}
inline void dfs1(int x,int f,int c)
{
	if(f && (mx[x]=max(mx[x],tot-siz[x]))<mx[G])G=x;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f && col[v]==c)
			dfs1(v,x,c);
}
inline void dfs2(int x,int f,int c,P p)
{
	vec.push_back(p),S.modify(p.first,1);
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f && col[v]==c)
			dfs2(v,x,c,P(p.first+1,p.second+edge[i].val));
}
inline void dfs3(int x,int f,int c,int c1,P p)
{
	col[x]=c1,vec.push_back(p),S.modify(p.first,1);
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f && col[v]==c)
			dfs3(v,x,c,c1,P(p.first+1,p.second+edge[i].val));
}
inline void solve(int x,int c)
{
	int g;dfs(x,0,c),tot=siz[x],dfs1(G=x,0,c),vec.clear(),dfs2(g=G,0,c,P(0,0)),sort(vec.begin(),vec.end(),cmp);
	for(int i=0,j=vec.size()-1;i<vec.size();++i)
	{
		S.modify(vec[i].first,-1);
		while(j>i && vec[i].second+vec[j].second>w)S.modify(vec[j].first,-1),--j;
		if(j<=i)break;
		ans+=S.query(l-vec[i].first);
	}
	for(int i=la[g],v;i;i=edge[i].nx)
		if(col[v=edge[i].to]==c)
		{
			vec.clear(),dfs3(v,g,c,++col_t,P(1,edge[i].val)),sort(vec.begin(),vec.end(),cmp);
			for(int j=0,k=vec.size()-1;j<vec.size();++j)
			{
				S.modify(vec[j].first,-1);
				while(k>j && vec[j].second+vec[k].second>w)S.modify(vec[k].first,-1),--k;
				if(k<=j)break;
				ans-=S.query(l-vec[j].first);
			}
			solve(v,col_t);
		}
}
int main()
{
	scanf("%d%d%d",&n,&l,&w),l=min(l,n-1);
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(i+1,x,y);
	solve(1,0),printf("%lld",ans);
	return 0;
}