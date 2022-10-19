#include<bits/stdc++.h>
#define B 11
#define LL long long
#define mod 998244353
using namespace std;
int n,c,mx,Mx,i0=0,i1=1,res;
LL tmp;
int a[3002],cnt[3002],sum[3002],pw[3002],ipw[3002];
LL fac[3002],inv[3002];
int f[3002][3002],g[3000/(B+1)+2][3002];
int dp[2][1502][1<<B];
inline LL Pow(int a,int b)
{
	if(!b)return 1;
	LL c=Pow(a,b>>1);
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline void init()
{
	fac[0]=1;for(int i=1;i<=n;++i)fac[i]=(fac[i-1]*i)%mod,ipw[i]=Pow(pw[i]=((pw[i-1]<<1)+1)%mod,mod-2);
	inv[n]=Pow(fac[n],mod-2);for(int i=n;i;--i)inv[i-1]=(inv[i]*i)%mod;
}
inline LL C(int a,int b)
{
	return (((fac[a]*inv[b])%mod)*inv[a-b])%mod;
}
inline void upd(int &x,int y)
{
	if((x+=y)>=mod)x-=mod;
}
inline void solve1()
{
	dp[0][0][0]=1,Mx=(1<<c)-1;
	for(int i=0;i<n;++i,i0^=1,i1^=1)
	{
		for(int j=0;j<=mx;++j)for(int k=0;k<=Mx;++k)dp[i1][j][k]=dp[i0][j][k];
		for(int j=0;j<=mx;++j)for(int k=0;k<Mx;++k)upd(dp[i1][j][k|(1<<a[i+1])],dp[i0][j][k]);
		for(int j=0;j<=mx;++j)upd(dp[i1][j+1][0],dp[i1][j][Mx]),dp[i1][j][Mx]=0;
	}
	for(int i=0;i<=mx;++i)
	{
		res=(i? 0:mod-1);
		for(int j=0;j<Mx;++j)upd(res,dp[i0][i][j]);
		printf("%d ",res);
	}
}
inline void solve2()
{
	g[0][n+1]=1;
	for(int i=n;i;--i)g[0][i]=(g[0][i+1]<<1)%mod;
	for(int i=1;i<=n;++i)
	{
		tmp=1,res=c;
		for(int j=0;j<c;++j)cnt[j]=0;
		for(int j=i;j<=n;++j)
		{
			if(!cnt[a[j]])--res;
			else if(a[j]^a[i])(tmp*=ipw[cnt[a[j]]])%=mod;
			++cnt[a[j]];
			if(a[j]^a[i])(tmp*=pw[cnt[a[j]]])%=mod;
			else if(j>i)(tmp<<=1)%=mod;
			f[i][j]=((res || a[i]==a[j])? 0:(tmp*ipw[cnt[a[j]]])%mod);
		}
		tmp=1;
		for(int j=0;j<c;++j)(tmp*=pw[cnt[j]])%=mod;
		upd(g[0][i],mod-(res? 0:tmp));
	}
	for(int i=1;i<=n;++i)upd(g[0][i],mod-g[0][i+1]);
	for(int i=0;i<mx;++i)
	{
		sum[n+1]=g[i][n+1];
		for(int j=n;j;--j)upd(sum[j]=sum[j+1],g[i][j]);
		for(int j=1;j<=n;++j)for(int k=j;k<=n;++k)g[i+1][j]=((LL)sum[k+1]*f[j][k]+g[i+1][j])%mod;
	}
	for(int i=0;i<=mx;++i)
	{
		res=0;
		for(int j=1;j<=n;++j)upd(res,g[i][j]);
		printf("%d ",res);
	}
}
int main()
{
	scanf("%d%d",&n,&c),mx=n/c,init();
	if(c==1)
	{
		for(int i=0;i<=n;++i)printf("%lld ",C(n,i)-(!i));
		return 0;
	}
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),--a[i];
	if(c<=B)solve1();
	else solve2();
	for(int i=mx+1;i<=n;++i)printf("0 ");
	return 0;
}