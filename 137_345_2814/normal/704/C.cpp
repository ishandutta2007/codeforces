#include<cstdio>
using namespace std;
#define N 100050
#define mod 1000000007
int in[N],is[N],n,m,k,a,b,c,dp[N][2][2],st[N],ct,vis[N],as1,as2,head[N],cnt=1;
struct edge{int t,next,v;}ed[N*2];
void adde(int f,int t,int v){ed[++cnt]=(edge){t,head[f],v};head[f]=cnt;ed[++cnt]=(edge){f,head[t],1<=v&&v<=2?v^3:v};head[t]=cnt;in[f]++;in[t]++;}
void dfs(int u,int fa){st[++ct]=u;vis[u]=1;for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa&&!vis[ed[i].t])dfs(ed[i].t,u);}
int que(int x,int y){for(int i=head[x];i;i=ed[i].next)if(ed[i].t==y)return ed[i].v;return 0;}
int que2(int x,int y){for(int i=head[x];i;i=ed[i].next)if(ed[i].t==y)return i;return 0;}
int que3(int x,int y,int c){for(int i=head[x];i;i=ed[i].next)if(ed[i].t==y&&i!=c&&(i^1)!=c)return ed[i].v;return 0;}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		if(a==1)
		{
			scanf("%d",&b);
			int fg=0;
			if(b<0)fg=1,b=-b;
			if(fg)is[b]^=2;else is[b]^=1;
		}
		else
		{
			scanf("%d%d",&b,&c);
			int fg=0;
			if(b<0)fg+=2,b=-b;
			if(c<0)fg+=1,c=-c;
			adde(b,c,fg);
		}
	}
	as1=1,as2=0;
	for(int i=1;i<=m;i++)if(in[i]==1&&!vis[i])
	{
		ct=0;dfs(i,0);
		for(int j=1;j<=ct;j++)for(int k=0;k<2;k++)for(int l=0;l<2;l++)dp[j][k][l]=0;
		dp[1][(is[i]&2)>>1][1]=dp[1][is[i]&1][0]=1;
		for(int j=2;j<=ct;j++)
		{
			int st1=que(st[j-1],st[j]);
			for(int k=0;k<2;k++)
			for(int l=0;l<2;l++)
			for(int t=0;t<2;t++)
			{
				int nt=l^((is[st[j]]&(t+1))?1:0);
				if(st1^3^(k?2:0)^(t?1:0))nt^=1;
				dp[j][nt][t]=(dp[j][nt][t]+dp[j-1][l][k])%mod;
			}
		}
		int v1=(dp[ct][0][0]+dp[ct][0][1])%mod,v2=(dp[ct][1][0]+dp[ct][1][1])%mod;
		int r1=(1ll*as1*v1+1ll*as2*v2)%mod,r2=(1ll*as1*v2+1ll*as2*v1)%mod;
		as1=r1,as2=r2;
	}
	else if(in[i]==0)
	{
		vis[i]=1;
		int v1=(is[i]&1?0:1)+(is[i]&2?0:1),v2=2-v1;
		int r1=(1ll*as1*v1+1ll*as2*v2)%mod,r2=(1ll*as1*v2+1ll*as2*v1)%mod;
		as1=r1,as2=r2;
	}
	for(int i=1;i<=m;i++)
	if(!vis[i])
	{
		ct=0;dfs(i,0);
		for(int j=1;j<=ct+1;j++)for(int k=0;k<2;k++)for(int l=0;l<2;l++)dp[j][k][l]=0;
		dp[1][(is[i]&2)>>1][1]=1;
		int ls=0;
		for(int j=2;j<=ct+1;j++)
		{
			int st1=que(st[j-1],st[j==ct+1?1:j]);
			if(ct==2&&j==ct+1)st1=que3(st[j-1],st[j==ct+1?1:j],ls);
			ls=que2(st[j-1],st[j==ct+1?1:j]);
			for(int k=0;k<2;k++)
			for(int l=0;l<2;l++)
			for(int t=0;t<2;t++)
			{
				if(j==ct+1&&t==0)continue;
				int nt=l^((is[st[j==ct+1?1:j]]&(t+1))?1:0);
				if(st1^3^(k?2:0)^(t?1:0))nt^=1;
				dp[j][nt][t]=(dp[j][nt][t]+dp[j-1][l][k])%mod;
			}
		}
		int v1=(dp[ct+1][0][0]+dp[ct+1][0][1])%mod,v2=(dp[ct+1][1][0]+dp[ct+1][1][1])%mod;
		for(int j=1;j<=ct+1;j++)for(int k=0;k<2;k++)for(int l=0;l<2;l++)dp[j][k][l]=0;
		dp[1][is[i]&1][0]=1;
		for(int j=2;j<=ct+1;j++)
		{
			int st1=que(st[j-1],st[j==ct+1?1:j]);
			if(ct==2&&j==ct+1)st1=que3(st[j-1],st[j==ct+1?1:j],ls);
			ls=que2(st[j-1],st[j==ct+1?1:j]);
			for(int k=0;k<2;k++)
			for(int l=0;l<2;l++)
			for(int t=0;t<2;t++)
			{
				if(j==ct+1&&t==1)continue;
				int nt=l^((is[st[j==ct+1?1:j]]&(t+1))?1:0);
				if(st1^3^(k?2:0)^(t?1:0))nt^=1;
				dp[j][nt][t]=(dp[j][nt][t]+dp[j-1][l][k])%mod;
			}
		}
		v1=(1ll*v1+dp[ct+1][0][0]+dp[ct+1][0][1])%mod,v2=(1ll*v2+dp[ct+1][1][0]+dp[ct+1][1][1])%mod;
		int r1=(1ll*as1*v1+1ll*as2*v2)%mod,r2=(1ll*as1*v2+1ll*as2*v1)%mod;
		as1=r1,as2=r2;
	}
	printf("%d\n",as2);
}