#include<cstdio>
#include<cstring>
const int N=1e5+5;
struct E{int to,next;}edge[N<<1];
int n,head[N],tot,col[N],son[N],num[N];
long long ans[N];
int getson(int u,int f)
{
	int sz=1,mx=0;
	for(int i=head[u];i!=-1;i=edge[i].next)if(edge[i].to!=f)
	{
		int tmp=getson(edge[i].to,u);
		if(tmp>mx)mx=tmp,son[u]=edge[i].to;
		sz+=tmp;
	}
	return sz;
}
int mx,skip;long long sum;
void modify(int u,int f,int t)
{
	num[col[u]]+=t;
	if(t>0&&num[col[u]]>=mx)
	{
		if(num[col[u]]>mx)mx=num[col[u]],sum=0;
		sum+=col[u];
	}
	for(int i=head[u];i!=-1;i=edge[i].next)if(edge[i].to!=f&&edge[i].to!=skip)modify(edge[i].to,u,t);
}
void dfs(int u,int f,int t)
{
	for(int i=head[u];i!=-1;i=edge[i].next)if(edge[i].to!=f&&edge[i].to!=son[u])dfs(edge[i].to,u,0);
	if(son[u])dfs(son[u],u,1),skip=son[u];
	modify(u,f,1);
	ans[u]=sum;
	if(son[u])skip=0;
	if(!t)modify(u,f,-1),mx=0,sum=0;
}
int main()
{
	memset(head,-1,sizeof(head));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&col[i]);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		edge[++tot]=(E){y,head[x]};head[x]=tot;
		edge[++tot]=(E){x,head[y]};head[y]=tot;
	}
	getson(1,0);
	dfs(1,0,0);
	for(int i=1;i<=n;i++)printf("%I64d ",ans[i]);
	return 0;
}