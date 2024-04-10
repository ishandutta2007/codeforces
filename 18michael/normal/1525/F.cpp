#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,n2,m,k,edge_t=0,cnt;
LL t;
int la[102]={},match[102];
LL X[52],Y[52];
int from[52][52];
LL dp[52][52];
bool vis[102],del[102]={};
vector<int> vec;
struct aaa
{
	int to,nx;
}edge[5002];
inline LL max(LL x,LL y)
{
	return x>y? x:y;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline bool dfs(int x)
{
	vis[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)
		if(!del[v=edge[i].to] && (!match[v] || (!vis[match[v]] && !del[match[v]] && dfs(match[v]))))
		{
			match[x]=v,match[v]=x;
			return 1;
		}
	return 0;
}
inline void work(int x,int y)
{
	if(!x)return ;
	work(x-1,from[x][y]);
	int l=y-from[x][y],res;
	for(int i=1;i<=n2;++i)
	{
		if(!l)break;
		if(!del[i])
		{
			res=n,del[i]=1,memset(match,0,sizeof(match));
			for(int j=1;j<=n;++j)if(!del[j])memset(vis,0,sizeof(vis)),res-=dfs(j);
			if(res>cnt)vec.push_back(i>n? n-i:i),--l,cnt=res;else del[i]=0;
		}
	}
	vec.push_back(0);
}
int main()
{
	scanf("%d%d%d",&n,&m,&k),cnt=n,n2=(n<<1);
	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),add_edge(x,n+y);
	for(int i=1;i<=n;++i)memset(vis,0,sizeof(vis)),cnt-=dfs(i);
	for(int i=1;i<=k;++i)scanf("%lld%lld",&X[i],&Y[i]);
	for(int i=0;i<=n;++i)
		for(int j=0;j<=n;++j)
			dp[i][j]=-inf;
	dp[0][0]=0;
	for(int i=1;i<=k;++i)
		for(int j=max(i-cnt+1,0);j<=n;++j)
		{
			dp[i][j]=0;
			for(int l=0;l<=j;++l)
				if((t=dp[i-1][j-l]+max(0,X[i]-Y[i]*l))>dp[i][j])
					dp[i][j]=t,from[i][j]=j-l;
		}
	if(k-cnt+1>=0)
	{
		work(k,k-cnt+1),printf("%d\n",vec.size());
		for(int i=0;i<vec.size();++i)printf("%d ",vec[i]);
	}
	else
	{
		printf("%d\n",k);
		for(int i=1;i<=k;++i)printf("0 ");
	}
	return 0;
}