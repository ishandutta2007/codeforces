#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=200005;
const int MOD=998244353;

int n,k,a[N],f[N];

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
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	f[1]=k-1;
	int p=(LL)(k-2)*ksm(k-1,MOD-2)%MOD;
	for (int i=2;i<=n;i++) f[i]=((LL)f[i-1]*(k-2)%MOD+(LL)f[i-2]*(k-1)%MOD)%MOD;
	int ans=1,s=0,ls=0;
	for (int i=1;i<=n;i+=2)
		if (a[i]==-1) s++;
		else
		{
			if (s)
			{
				if (!ls) ans=(LL)ans*(f[s]+f[s-1])%MOD;
				else if (ls==a[i]) ans=(LL)ans*f[s]%MOD;
				else ans=(LL)ans*(f[s-1]+(LL)f[s]*p%MOD)%MOD;
			}
			else if (ls==a[i]) ans=0;
			ls=a[i];s=0;
		}
	if (s)
	{
		if (!ls) ans=(LL)ans*k%MOD*(s>1?(f[s-1]+f[s-2]):1)%MOD;
		else ans=(LL)ans*(f[s]+f[s-1])%MOD;
	}
	s=ls=0;
	for (int i=2;i<=n;i+=2)
		if (a[i]==-1) s++;
		else
		{
			if (s)
			{
				if (!ls) ans=(LL)ans*(f[s]+f[s-1])%MOD;
				else if (ls==a[i]) ans=(LL)ans*f[s]%MOD;
				else ans=(LL)ans*(f[s-1]+(LL)f[s]*p%MOD)%MOD;
			}
			else if (ls==a[i]) ans=0;
			ls=a[i];s=0;
		}
	if (s)
	{
		if (!ls) ans=(LL)ans*k%MOD*(s>1?(f[s-1]+f[s-2]):1)%MOD;
		else ans=(LL)ans*(f[s]+f[s-1])%MOD;
	}
	printf("%d\n",ans);
	return 0;
}