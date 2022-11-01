#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=100005;
const int MOD=1000000007;

int n,tot,pri[N],mu[N],f[N],s[N],a[N][205];
bool not_prime[N];

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

void get_mu(int n)
{
	mu[1]=1;
	for (int i=2;i<=n;i++)
	{
		if (!not_prime[i]) pri[++tot]=i,mu[i]=-1;
		for (int j=1;j<=tot&&i*pri[j]<=n;j++)
		{
			not_prime[i*pri[j]]=1;
			if (i%pri[j]==0) break;
			mu[i*pri[j]]=-mu[i];
		}
	}
}

int get(int m,int n)
{
	int ans=mu[m]*(n/m);
	for (int i=1;i<=s[m];i++)
		ans+=(n/a[m][i])*mu[a[m][i]];
	return ans;
}

int main()
{
	scanf("%d",&n);
	int ny=ksm(n,MOD-2);
	get_mu(n);
	for (int i=1;i<=n;i++)
		for (int j=i*2;j<=n;j+=i)
			a[j][++s[j]]=i;
	f[1]=0;
	for (int i=2;i<=n;i++)
	{
		int p=(LL)(n/i)*ny%MOD;
		f[i]=p;
		for (int j=1;j<=s[i];j++)
		{
			int x=a[i][j],y=get(i/x,n/x);
			(f[i]+=(LL)(f[x]+1)*y%MOD*ny%MOD)%=MOD;
		}
		f[i]=(LL)f[i]*ksm(1+MOD-p,MOD-2)%MOD;
	}
	int ans=1;
	for (int i=1;i<=n;i++) (ans+=(LL)f[i]*ny%MOD)%=MOD;
	printf("%d\n",ans);
	return 0;
}