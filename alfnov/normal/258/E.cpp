#include<bits/stdc++.h>
using namespace std;
struct apple
{
	int l,r,gs;
	apple(int l=0,int r=0,int gs=0):l(l),r(r),gs(gs){}
};
vector<int>g[100005];
int tot=0,bg[100005],en[100005],gb[100005],ans[100005];
int s1[400005],s2[400005],lz[400005];
void dfs(int x,int la)
{
	bg[x]=en[x]=++tot,gb[bg[x]]=x;
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(cu==la)continue;
		dfs(cu,x);
		en[x]=en[cu];
	}
}
vector<apple>jt[100005];
void addr(int l1,int r1,int l2,int r2)
{
	jt[l2].push_back(apple(l1,r1,1));
	jt[r2+1].push_back(apple(l1,r1,-1));
}
void pushdown(int l,int r,int o)
{
	lz[o<<1]+=lz[o],lz[o<<1|1]+=lz[o];
	s1[o<<1]+=lz[o],s1[o<<1|1]+=lz[o];
	lz[o]=0;
}
void add(int l,int r,int o,int ll,int rr,int x)
{
	if(l>=ll&&r<=rr)
	{
		s1[o]+=x,lz[o]+=x;
		return;
	}
	pushdown(l,r,o);
	int mid=l+r>>1;
	if(mid>=ll)add(l,mid,o<<1,ll,rr,x);
	if(mid<rr)add(mid+1,r,o<<1|1,ll,rr,x);
	s1[o]=min(s1[o<<1],s1[o<<1|1]),s2[o]=0;
	if(s1[o<<1]==s1[o])s2[o]+=s2[o<<1];
	if(s1[o<<1|1]==s1[o])s2[o]+=s2[o<<1|1];
}
void build(int l,int r,int o)
{
	s1[o]=0,s2[o]=r-l+1;
	if(l==r)return;
	int mid=l+r>>1;
	build(l,mid,o<<1);
	build(mid+1,r,o<<1|1);
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	while(m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		addr(bg[a],en[a],bg[a],en[a]);
		addr(bg[a],en[a],bg[b],en[b]);
		addr(bg[b],en[b],bg[a],en[a]);
		addr(bg[b],en[b],bg[b],en[b]);
	}
	for(int i=1;i<=n;i++)addr(bg[i],bg[i],bg[i],bg[i]);
	build(1,n,1);
	for(int i=1;i<=n;i++)
	{
		int x=gb[i];
		for(int j=0;j<jt[i].size();j++)
		{
			apple ll=jt[i][j];
			add(1,n,1,ll.l,ll.r,ll.gs);
		}
		if(s1[1]==0)ans[x]=n-s2[1]-1;
		else ans[x]=n-1;
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}