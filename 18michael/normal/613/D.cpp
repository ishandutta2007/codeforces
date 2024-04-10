#include<cstdio>
#include<algorithm>
#define Mx 16
#define inf 0x1f1f1f1f
using namespace std;
int n,edge_t=0,q,k,dfn_t=0,e_t,vec_t=0,st_t;bool ok;
int la[100002]={},lae[100002]={},dep[100002],a[100002],dfn[100002],st[100002],vec[100002];
bool u[100002]={};
int fa[100002][18],dp[100002][2];
struct aaa
{
	int to,nx;
}edge[200002],e[200002];
inline bool cmp(int a,int b)
{
	return dfn[a]<dfn[b]? 1:0;
}
inline int abs(int x)
{
	return x>0? x:-x;
}
inline int min(int x,int y)
{
	return x<y? x:y;
}
inline void swap(int &x,int &y)
{
	int z=x;x=y,y=z;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void add_e(int x,int y)
{
	e[++e_t]=(aaa){y,lae[x]},lae[x]=e_t;
}
inline void dfs(int x,int f,int d)
{
	fa[x][0]=f,dep[x]=d,dfn[x]=(++dfn_t);
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs(v,x,d+1);
}
inline void get_LCA()
{
	for(int i=1;i<=Mx;++i)
		for(int j=1;j<=n;++j)
			fa[j][i]=fa[fa[j][i-1]][i-1];
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=Mx;~i;--i)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	if(x==y)return x;
	for(int i=Mx;~i;--i)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
inline void clear()
{
	for(int i=1;i<=vec_t;++i)lae[vec[i]]=u[vec[i]]=0;
	e_t=st_t=vec_t=0;
}
inline void init()
{
	clear(),st[++st_t]=vec[++vec_t]=a[0]=1;
	for(int i=1;i<=k;++i)u[a[i]]=1;
	for(int i=1+(a[1]==1),j;i<=k;++i)
	{
		j=LCA(a[i],a[i-1]);
		while(st_t>1 && dep[j]<dep[st[st_t-1]])add_e(st[st_t-1],st[st_t]),--st_t;
		if(st[st_t]!=j)
		{
			add_e(j,st[st_t]),--st_t;
			if(st[st_t]!=j)st[++st_t]=vec[++vec_t]=j;
		}
		if(st[st_t]!=a[i])st[++st_t]=vec[++vec_t]=a[i];
	}
	for(int i=2;i<=st_t;++i)add_e(st[i-1],st[i]);
}
inline void dfs1(int x,int f)
{
	int tot=0,mn=inf,sum=0;
	dp[x][0]=1+u[x]*inf,dp[x][1]=0;
	for(int i=lae[x],v;i;i=e[i].nx)
		if((v=e[i].to)!=f)
		{
			dfs1(v,x);
			if(u[x])dp[x][1]+=min(dp[v][0],dp[v][1]+1),ok|=(u[v] && fa[v][0]==x);
			else tot+=(u[v] && fa[v][0]==x),sum=min(sum+dp[v][0],inf),dp[x][0]+=min(dp[v][0],dp[v][1]),dp[x][1]=min(dp[x][1]+dp[v][0],2*inf),mn=min(mn,dp[v][1]-dp[v][0]);
		}
	if(!u[x])
	{
		dp[x][0]=min(dp[x][0],sum),dp[x][1]+=mn;
		if(tot>1)dp[x][1]=inf;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	dfs(1,0,1),get_LCA(),scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&k),ok=0;for(int i=1;i<=k;++i)scanf("%d",&a[i]);
		sort(a+1,a+k+1,cmp),init(),dfs1(1,0),printf("%d\n",ok? -1:min(dp[1][0],dp[1][1]));
	}
	return 0;
}