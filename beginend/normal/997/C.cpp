#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=1000005;
const int MOD=998244353;

int n,ny[N],jc[N],dp[N][5];

int C(int n,int m)
{
	return (LL)jc[n]*ny[m]%MOD*ny[n-m]%MOD;
}

int ksm(int x,int y)
{
	int ans=1;
	while (y)
	{
		if (y&1) ans=(LL)ans*x%MOD;
		x=(LL)x*x%MOD;y>>=1;
	}
	return ans;
}

int main()
{
	scanf("%d",&n);
	jc[0]=jc[1]=ny[0]=ny[1]=1;
	for (int i=2;i<=n;i++) jc[i]=(LL)jc[i-1]*i%MOD,ny[i]=(LL)(MOD-MOD/i)*ny[MOD%i]%MOD;
	for (int i=2;i<=n;i++) ny[i]=(LL)ny[i-1]*ny[i]%MOD;
	dp[0][0]=dp[1][1]=1;
	for (int i=1;i<n;i++)
		for (int j=1;j<=3;j++)
		{
			(dp[i+1][j]+=(LL)dp[i][j]*j%MOD)%=MOD;
			if (j<3) (dp[i+1][j+1]+=dp[i][j])%=MOD;
		}
	int ans=0;
	for (int i=1;i<=n;i++)
		if (i&1) (ans+=(LL)ksm(3,i)*C(n,i)%MOD*ksm(3,(LL)n*(n-i)%(MOD-1))%MOD)%=MOD;
		else (ans-=(LL)ksm(3,i)*C(n,i)%MOD*ksm(3,(LL)n*(n-i)%(MOD-1))%MOD)%=MOD;
	for (int i=1;i<=n;i++)
	{
		int r=(LL)6*(dp[i][2]+dp[i][3])%MOD;
		int w=(LL)r*ksm(3,(LL)n*(n-i)%(MOD-1))%MOD;
		r=(LL)6*(dp[n-i][2]+dp[n-i][3])%MOD;
		int t=(dp[n-i][1]*2%MOD+r)%MOD;
		(w+=(LL)3*ksm(t,n)%MOD)%=MOD;
		w=(LL)w*C(n,i)%MOD;
		if (i&1) (ans+=w)%=MOD;
		else (ans-=w)%=MOD;
	}
	printf("%d",(ans+MOD)%MOD);
	return 0;
}