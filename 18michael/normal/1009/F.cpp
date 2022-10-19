#include<cstdio>
int n,edge_t=0,vec_t=0,mx=0;
int la[1000002]={},siz[1000002]={},son[1000002]={},dep[1000002],cnt[1000002]={},ans[1000002],vec[1000002];
struct aaa
{
	int to,nx;
}edge[2000002];
inline void clear()
{
	for(int i=1;i<=vec_t;++i)cnt[vec[i]]=0;
	vec_t=mx=0;
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
inline void dfs1(int x,int f,int t)
{
	if(t)for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f && v!=son[x])
			dfs1(v,x,1),clear();
	if(son[x])dfs1(son[x],x,t);
	if(!cnt[dep[x]])vec[++vec_t]=dep[x];++cnt[dep[x]];
	if(cnt[dep[x]]>cnt[mx] || (cnt[dep[x]]==cnt[mx] && dep[x]<mx))mx=dep[x];
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f && v!=son[x])
			dfs1(v,x,0);
	if(t)ans[x]=mx-dep[x];
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	dfs(1,0,1),dfs1(1,0,1);
	for(int i=1;i<=n;++i)printf("%d\n",ans[i]);
	return 0;
}