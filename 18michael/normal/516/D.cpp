#include<cstdio>
#define LL long long
int n,edge_t=0,num,q,st_t=0,ans,l,r,mid;LL t,L;
int la[100002]={},st[100002],cnt[100002],fa[100002];
LL dep[100002]={};
struct aaa
{
	int to,nx,val;
}edge[200002];
inline LL max(LL x,LL y)
{
	return x>y? x:y;
}
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],z},la[y]=edge_t;
}
inline void dfs(int x,int f,LL d)
{
	dep[x]=max(dep[x],d);
	if(d>t)t=d,num=x;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs(v,x,d+edge[i].val);
}
inline void dfs1(int x,int f)
{
	for(fa[st[++st_t]=x]=f,l=1,r=st_t;l<=r;)
	{
		mid=((l+r)>>1);
		if(dep[x]-dep[st[mid]]<=L)r=mid-1;
		else l=mid+1;
	}
	++cnt[x],--cnt[fa[st[l]]];
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs1(v,x),cnt[x]+=cnt[v];
	--st_t,ans=max(ans,cnt[x]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y,z;i<n;++i)scanf("%d%d%d",&x,&y,&z),add_edge(x,y,z);
	dfs(num=1,0,t=0),dfs(num,0,t=0),dfs(num,0,t=0),t=dep[num=1];
	for(int i=2;i<=n;++i)if(dep[i]<t)t=dep[num=i];
	for(scanf("%d",&q);q--;)
	{
		for(int i=1;i<=n;++i)cnt[i]=0;
		scanf("%lld",&L),dfs1(num,ans=0),printf("%d\n",ans);
	}
	return 0;
}