#include<cstdio>
#define LL long long
int n,edge_t=0,vec_t=0,Mx=0;LL cnt=0;
int c[100002],la[100002]={},son[100002]={},siz[100002]={},tim[100002]={},vec[100002];
LL ans[100002]={};
struct aaa
{
	int to,nx;
}edge[200002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int fa)
{
	siz[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=fa)
		{
			dfs(v,x),siz[x]+=siz[v];
			if(siz[v]>siz[son[x]])son[x]=v;
		}
}
inline void dfs1(int x,int fa,int opt)
{
	if(!ans[x])
		for(int i=la[x],v;i;i=edge[i].nx)
			if((v=edge[i].to)!=fa && v!=son[x])
				dfs1(v,x,0);
	if(son[x])dfs1(son[x],x,1);
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=fa && v!=son[x])
			dfs1(v,x,1);
	if(!tim[c[x]])vec[++vec_t]=c[x];
	if((++tim[c[x]])>Mx)Mx=tim[c[x]],cnt=c[x];
	else if(tim[c[x]]==Mx)cnt+=c[x];
	if(!ans[x])ans[x]=cnt;
	if(!opt)
	{
		for(int i=1;i<=vec_t;++i)tim[vec[i]]=0;
		vec_t=cnt=Mx=0;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&c[i]);
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	dfs(1,1),dfs1(1,1,1);
	for(int i=1;i<=n;++i)printf("%lld ",ans[i]);
	return 0;
}