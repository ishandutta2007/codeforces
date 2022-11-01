#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=1005;
const int MOD=998244353;

int n,k,a[N],f[N][N],cnt[100005];

int solve(int x)
{
	for (int i=0;i<=n;i++)
		for (int j=0;j<=k;j++)
			f[i][j]=0;
	f[0][0]=1;
	int p=0;
	for (int i=1;i<=n;i++)
	{
		while (p<i&&a[i]-a[p+1]>=x) p++;
		f[i][0]=1;
		for (int j=1;j<=std::min(i,k);j++) f[i][j]=(f[p][j-1]+f[i-1][j])%MOD;
	}
	return f[n][k];
}

int main()
{
	scanf("%d%d",&n,&k);
	int mx=0;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),mx=std::max(mx,a[i]);
	std::sort(a+1,a+n+1);
	int T=mx/(k-1);
	for (int i=1;i<=T;i++) cnt[i]=solve(i);
	int ans=0;
	for (int i=1;i<=T;i++) (ans+=(LL)i*(cnt[i]-cnt[i+1])%MOD)%=MOD;
	ans+=ans<0?MOD:0;
	printf("%d\n",ans);
	return 0;
}