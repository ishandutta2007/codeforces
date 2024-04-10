#include<cstdio>
#define LL long long
#define mod 998244353
int n,edge_t=0;
LL ans=0;
int la[300002]={};
LL dp[300002][3];
struct aaa
{
	int to,nx;
}edge[600002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int f)
{
	LL res1=1,res2=1,res3=1,res4=0,res5=1;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs(v,x),res1=(res1*(dp[v][0]+1+dp[v][1]+dp[v][2]))%mod,res2=(res2*(3*dp[v][0]+3+2*dp[v][1]+2*dp[v][2]))%mod,res3=(res3*(2*dp[v][0]+2+2*dp[v][1]+dp[v][2]))%mod;
	dp[x][0]=res1-1,dp[x][1]=(res2-res1)%mod,dp[x][2]=(res3-res1)%mod;
}
int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i)scanf("%d%d",&u,&v),add_edge(u,v);
	dfs(1,0),printf("%lld",(((dp[1][0]+dp[1][1]+dp[1][2])%mod)+mod)%mod);
	return 0;
}