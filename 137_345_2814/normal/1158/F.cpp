#include<cstdio>
using namespace std;
#define N 3021
#define mod 998244353
int n,c,v[N];
int pw(int a,int p){int as=1;while(p){if(p&1)as=1ll*as*a%mod;a=1ll*a*a%mod;p>>=1;}return as;}
struct n3c{
	int dp[N][N],f[N][N],g[N],s[N],c1[N];
	void solve()
	{
		for(int i=1;i<=n;i++)s[i]=1ll*(pw(2,i+1)-1)*pw(pw(2,i)-1,mod-2)%mod;
		for(int i=0;i<=n;i++)
		{
			for(int j=1;j<=c;j++)c1[j]=0;
			int s1=c-1,v1=1;
			for(int j=i-1;j>=1;j--)
			{
				if(v[j]!=v[i])if(!c1[v[j]])s1--;else v1=1ll*v1*s[c1[v[j]]]%mod;
				c1[v[j]]++;
				f[j][i]=s1?0:v1;
			}
			for(int j=1;j<=c;j++)c1[j]=0;
			s1=c,v1=1;int tp=1;
			for(int j=i+1;j<=n;j++)
			{
				if(!c1[v[j]])s1--;else v1=1ll*v1*s[c1[v[j]]]%mod;
				c1[v[j]]++;tp=2ll*tp%mod;
			}
			if(!s1)tp=(tp-v1+mod)%mod;
			g[i]=tp;
		}
		dp[0][0]=1;
		for(int i=0;i<n;i++)
		for(int j=0;j<=i/c;j++)if(dp[i][j])
		for(int k=i+1;k<=n;k++)dp[k][j+1]=(dp[k][j+1]+1ll*f[i+1][k]*dp[i][j])%mod;
		for(int i=0;i<=n;i++)
		{
			int as=0;
			for(int j=0;j<=n;j++)as=(as+1ll*dp[j][i]*g[j])%mod;
			if(i==0)as=(as-1+mod)%mod;
			printf("%d ",as);
		}
	}
}s1;
struct n2c2c{
	int dp[2][N][N];
	void solve()
	{
		dp[0][0][0]=1;
		for(int i=1;i<=n;i++)
		for(int j=0;j<=(i-1)/c;j++)
		for(int l=0;l<1<<c;l++)
		{
			dp[i&1][j][l]=(dp[i&1][j][l]+dp[~i&1][j][l])%mod;
			int v1=j,v2=l|(1<<v[i]-1);
			if(v2==(1<<c)-1)v1++,v2=0;
			dp[i&1][v1][v2]=(dp[i&1][v1][v2]+dp[~i&1][j][l])%mod;
			dp[~i&1][j][l]=0;
		}
		for(int i=0;i<=n;i++)
		{
			int as=0;
			for(int j=0;j<1<<c;j++)as=(as+1ll*dp[n&1][i][j])%mod;
			if(i==0)as=(as-1+mod)%mod;
			printf("%d ",as);
		}
	}
}s2;
int main()
{
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	if((c>20||(1<<c)>n)&&c>1)s1.solve();else s2.solve();
}