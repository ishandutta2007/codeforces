#include<bits/stdc++.h>
namespace _
{
	int n,p;
	int fac[555],C[555][555];
	int add(int x,int y){return(x+y)<p?(x+y):(x+y-p);}
	int dp[505][250005];
	int calc(int n)
	{
		register int i,ii,d;
		for(i=1;i<=n;i++)
			for(ii=0;ii<=n*(n+1);ii++)dp[i][ii]=0;
		const int M=n*(n+1)/2;
		for(i=1;i<n;i++)dp[1][M-i]=n-i;
		for(i=2;i<=n;i++)
		{
			/*
			for(int si=0;si<=n*(n+1);si++)
			{
				if(si==M)printf("(");
				printf("%d",dp[i-1][si]);
				if(si==M)printf(")");
				printf(" ");
			}puts("");
			*/
			int cs=n-i;
			for(d=-cs;d<=0;d++)
			{
				//printf("> %d\n",cs+d+1);
				for(ii=0;ii<=n*(n+1)+d;ii++)
					dp[i][ii]=(dp[i][ii]+dp[i-1][ii+d]*1ll*
					(cs+d+1))%p;
			}
			for(d=1;d<=cs;d++)
			{
				//printf("> %d\n",cs-d+1);
				for(ii=d;ii<=n*(n+1);ii++)
					dp[i][ii]=(dp[i][ii]+dp[i-1][ii+d]*1ll*
					(cs-d+1))%p;
			}
		}
		long long ans=0;
		for(ii=M+1;ii<=n*(n+1);ii++)ans+=dp[n][ii];
		//printf("%lld\n",ans);
		return ans%p;
	}
	void solve()
	{
		//fprintf(stderr,"%d\n",sizeof dp >>20);
		scanf("%d%d",&n,&p);
		register int i,ii;
		for(i=fac[0]=1;i<=n;i++)fac[i]=fac[i-1]*1ll*i%p;
		for(i=C[0][0]=1;i<=n;i++)
			for(ii=C[i][0]=1;ii<=i;ii++)
				C[i][ii]=add(C[i-1][ii-1],C[i-1][ii]);
		long long ans=0;
		for(i=1;i<=n;i++)ans+=C[n][i]*1ll*fac[n-i]%p*calc(i)%p;
		printf("%lld\n",ans%p);
	}
}
int main()
{
	int T=1;
	//scanf("%d",&T);
	while(T--)_::solve();
}