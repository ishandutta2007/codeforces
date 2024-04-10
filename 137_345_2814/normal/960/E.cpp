#include<cstdio>
#include<algorithm>
using namespace std;
int n,cnt,head[200005],v[200005],mod=1e9+7,a,b;
long long dp[200001][2],ans,ans2;
struct edge{
	int t,next;
}ed[400005];
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
	dp[u][0]=1;
	dp[u][1]=0;
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa)
	{
		dfs(ed[i].t,u);
		ans=(ans+1ll*v[u]*dp[u][0]%mod*dp[ed[i].t][1]-1ll*v[u]*dp[u][1]%mod*dp[ed[i].t][0])%mod;
		dp[u][0]+=dp[ed[i].t][1];
		dp[u][1]+=dp[ed[i].t][0];
	}
}
void dfs2(int u,int fa)
{
	if(u-1)
	swap(dp[1][0],dp[1][1]);
	ans=(ans+1ll*v[u]*dp[u][0]%mod*(dp[1][0]-dp[u][0])-1ll*v[u]*dp[u][1]%mod*(dp[1][1]-dp[u][1]))%mod;
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa)
	dfs2(ed[i].t,u);
	swap(dp[1][0],dp[1][1]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&v[i]),ans2+=v[i];
	ans2=(ans2%mod+mod)%mod;
	for(int i=1;i<n;i++)
	scanf("%d%d",&a,&b),adde(a,b);
	dfs(1,0);
	dfs2(1,0);
	printf("%lld\n",(ans*2%mod+mod+ans2)%mod);
}//2445676879098546739878363421