#include<bits/stdc++.h>
namespace _
{
	const int mod=998244353;
	char typ[1111][11];
	int a[1111],p[1111],n;
	int dp[505][505];
	int rnk[1111];
	int add(int x,int y){return(x+y)<mod?(x+y):(x+y-mod);}
	int calc(int pos,int rkp)
	{
		memset(dp,0,sizeof dp);
		dp[0][0]=1;
		for(register int i=1;i<pos;i++)
		{
			if(typ[i][0]=='-')
			{
				for(register int ii=0;ii<=i;ii++)
					dp[i][ii]=add(dp[i-1][ii],dp[i-1][ii+1]);
				dp[i][0]=add(dp[i][0],dp[i-1][0]);
			}
			else if(rnk[i]<rkp)
			{
				dp[i][0]=dp[i-1][0];
				for(register int ii=1;ii<=i;ii++)
					dp[i][ii]=add(dp[i-1][ii],dp[i-1][ii-1]);
			}
			else
			{
				for(register int ii=0;ii<=i;ii++)
					dp[i][ii]=add(dp[i-1][ii],dp[i-1][ii]);
			}
		}
		for(register int ii=1;ii<=pos;ii++)
			dp[pos][ii]=dp[pos-1][ii-1];
		for(register int i=pos+1;i<=n;i++)
		{
			if(typ[i][0]=='-')
			{
				for(register int ii=1;ii<=i;ii++)
					dp[i][ii]=add(dp[i-1][ii],dp[i-1][ii+1]);
			}
			else if(rnk[i]<rkp)
			{
				for(register int ii=1;ii<=i;ii++)
					dp[i][ii]=add(dp[i-1][ii],dp[i-1][ii-1]);
			}
			else
			{
				for(register int ii=1;ii<=i;ii++)
					dp[i][ii]=add(dp[i-1][ii],dp[i-1][ii]);
			}
		}
		int ret=0;
		for(register int ii=1;ii<=n;ii++)
			ret=(ret+dp[n][ii])%mod;
		//printf("%d %d %d\n",ret,dp[n][1],dp[n][2]);
		return ret;
	}
	void solve()
	{
		scanf("%d",&n);
		register int i;
		int stk[11111],top=0;
		for(i=1;i<=n;i++)
		{
			scanf("%s",typ[i]);
			if(typ[i][0]=='+')scanf("%d",a+i),stk[++top]=i;
		}
		std::sort(stk+1,stk+top+1,[&](int x,int y)
		{return a[x]<a[y];});
		for(i=1;i<=top;i++)rnk[stk[i]]=i;
		int ans=0;
		for(i=1;i<=top;i++)
		{
			int p=stk[i];
			ans=(ans+calc(p,i)*1ll*a[p])%mod;
		}
		printf("%d\n",ans);
	}
}
int main()
{
	int T=1;
	//scanf("%d",&T);
	while(T--)_::solve();
}