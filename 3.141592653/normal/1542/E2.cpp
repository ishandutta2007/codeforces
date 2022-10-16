#include<bits/stdc++.h>
namespace _
{
	int N,p;
	int fac[555],C[555][555];
	int add(int x,int y){return(x+y)<p?(x+y):(x+y-p);}
	int dp[505][255005],sp[255005];
	int rangeS(int l,int r)
	{
		if(!l)return sp[r];
		return add(sp[r],p-sp[l-1]);
	}
	int calc(int n)
	{
		register int i,ii,d;
		const int M=n*(n+1)/2+(n*4)+5;
		const int Max=M<<1;
		for(i=1;i<=n;i++)
		{
			int cs=n-i;
			sp[0]=dp[i-1][0];
			for(ii=1;ii<=Max;ii++)
				sp[ii]=add(dp[i-1][ii],sp[ii-1]);
			int S=0;
			for(ii=0;ii+cs<=Max;ii++)
			{
				S=add(S,rangeS(ii,ii+cs));
				if(ii>=cs)
				{
					dp[i][ii]=S;
					S=add(S,p-rangeS(ii-cs,ii));
				}
			}/*
			for(int si=0;si<=Max;si++)
			{
				if(si==M)printf("(");
				printf("%d",dp[i-1][si]);
				if(si==M)printf(")");
				printf(" ");
			}puts("");*/
			for(d=1;d<=cs;d++)
			{
				dp[i][M-d]=(dp[i][M-d]+C[N][i-1]*1ll*fac[i-1]%p
				*(cs-d+1))%p;
			}
		}
		long long ans=0;
		for(ii=M+1;ii<=Max;ii++)ans+=dp[n][ii];
		return ans%p;
	}
	void solve()
	{
		//fprintf(stderr,"%d\n",sizeof dp >>20);
		scanf("%d%d",&N,&p);
		register int i,ii;
		for(i=fac[0]=1;i<=N;i++)fac[i]=fac[i-1]*1ll*i%p;
		for(i=C[0][0]=1;i<=N;i++)
			for(ii=C[i][0]=1;ii<=i;ii++)
				C[i][ii]=add(C[i-1][ii-1],C[i-1][ii]);
		printf("%d\n",calc(N));
	}
}
int main()
{
	int T=1;
	//scanf("%d",&T);
	while(T--)_::solve();
}