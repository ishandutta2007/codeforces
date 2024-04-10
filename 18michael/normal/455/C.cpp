#include<cstdio>
int n,m,q,D,num,edge_t=0,ans=0,opt;
int la[300002]={},dep[300002],rt[300002]={},mx[300002]={},sec[300002]={};
struct aaa
{
	int to,nx;
}edge[600002];
inline void swap(int &x,int &y)
{
	int z=x;x=y,y=z;
}
inline int max(int a,int b)
{
	return a>b? a:b;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int f,int d)
{
	if((dep[x]=d)>D)D=dep[x],num=x;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs(v,x,d+1);
}
inline void dfs1(int x,int d)
{
	if(!d)
	{
		num=x;
		return ;
	}
	for(int i=la[x],v;i;i=edge[i].nx)
		if(dep[v=edge[i].to]==dep[x]-1)
		{
			dfs1(v,d);
			return ;
		}
}
inline void dfs2(int x,int f,int z)
{
	rt[x]=z;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs2(v,x,z);
}
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	for(int i=1;i<=n;++i)
		if(!rt[i])
			D=0,dfs(i,0,1),D=0,dfs(num,0,1),dfs1(num,D/2),mx[num]=D/2,sec[num]=(D-1)/2,dfs2(i,0,num),ans=max(ans,mx[i]);
	for(int i=1,x,y;i<=q;++i)
	{
		scanf("%d",&opt);
		if(opt==1)scanf("%d",&x),getroot(x),printf("%d\n",mx[rt[x]]+sec[rt[x]]);
		else
		{
			scanf("%d%d",&x,&y),getroot(x),getroot(y),x=rt[x],y=rt[y];
			if(x==y)continue;
			if(mx[x]>mx[y])swap(x,y);
			rt[x]=y;
			if(mx[x]+1>mx[y])sec[y]=mx[y],mx[y]=mx[x]+1;
			else if(mx[x]+1>sec[y])sec[y]=mx[x]+1;
		}
	}
	return 0;
}