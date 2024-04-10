#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=5005;
const int MOD=1000000007;

int n,f[N],k;

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

int dwm(int x,int y)
{
	int ans=1;
	while (y--)
	{
		ans=(LL)ans*x%MOD;
		x--;
	}
	return ans;
}

int main()
{
	scanf("%d%d",&n,&k);
	f[0]=1;int s=1;
	for (int i=1;i<=n;i++)
	{
		int a;scanf("%d",&a);
		s=(LL)s*a%MOD;
		for (int j=i;j>=1;j--) f[j]=((LL)f[j]*a%MOD+MOD-f[j-1])%MOD;
		f[0]=(LL)f[0]*a%MOD;
	}
	int ans=0;
	for (int i=0;i<=min(n,k);i++) (ans+=(LL)ksm(n,k-i)*dwm(k,i)%MOD*f[i]%MOD)%=MOD;
	ans=(LL)ans*ksm(n,(LL)k*(MOD-2)%(MOD-1))%MOD;
	ans=(s+MOD-ans)%MOD;
	printf("%d",ans);
	return 0;
}