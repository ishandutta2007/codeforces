#include<cstdio>
#define LL long long
int n,edge_t=0;LL ans=0;
int la[3002]={};
int fa[3002][3002];//size/fa[i][j]i 
LL size[3002][3002],mx[3002][3002];
struct aaa
{
	int to,nx;
}edge[6002];
inline LL max(LL a,LL b)
{
	return a>b? a:b;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int root,int now,int f)
{
	size[root][now]=1,fa[root][now]=f;
	for(int i=la[now],j;i;i=edge[i].nx)
		if((j=edge[i].to)!=f)
			dfs(root,j,now),size[root][now]+=size[root][j];
}
inline void dp(int x,int y)
{
	if(x!=fa[x][y] && !mx[x][fa[x][y]])dp(x,fa[x][y]);
	if(fa[y][x]!=y && !mx[fa[y][x]][y])dp(fa[y][x],y);
	mx[x][y]=max(mx[x][fa[x][y]],mx[fa[y][x]][y])+size[x][y]*size[y][x];
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<n;++i)
		scanf("%d%d",&x,&y),add_edge(x,y);
	for(int i=1;i<=n;++i)dfs(i,i,i);
	for(int i=1;i<n;++i)
		for(int j=i+1;j<=n;++j)
			dp(i,j),ans=max(ans,mx[i][j]);
	printf("%lld",ans);
	return 0;
}