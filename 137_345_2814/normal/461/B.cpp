#include<cstdio>
using namespace std;
int n,v[100001],dp[100001][2],head[100001],cnt,a;
struct edge{
	int t,next;
}ed[200001];
void adde(int f,int t)
{
	ed[++cnt].t=t;
	ed[cnt].next=head[f];
	head[f]=cnt;
	ed[++cnt].t=f;
	ed[cnt].next=head[t];
	head[t]=cnt;
}
void dfs(int u,int fa)
{
	dp[u][v[u]]=1;
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa)
	{
		dfs(ed[i].t,u);
		dp[u][1]=(1ll*dp[u][1]*dp[ed[i].t][0]+1ll*dp[u][0]*dp[ed[i].t][1])%1000000007;
		dp[u][0]=1ll*dp[u][0]*dp[ed[i].t][0]%1000000007;
	}
	dp[u][0]=(dp[u][0]+dp[u][1])%1000000007;
}
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	scanf("%d",&a),adde(a+1,i);
	for(int i=1;i<=n;i++)
	scanf("%d",&v[i]);
	dfs(1,0);
	printf("%d\n",dp[1][1]);
}