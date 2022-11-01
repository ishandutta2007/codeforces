#include<bits/stdc++.h>

typedef long long LL;

const int MOD=1000000007;

int x;
LL n;

int ksm(int x,LL y)
{
	int ans=1;
	while (y)
	{
		if (y&1) ans=(LL)ans*x%MOD;
		x=(LL)x*x%MOD;y>>=1;
	}
	return ans;
}

int calc(int p)
{
	LL t=1;
	int ans=1;
	while (t<=n/p) t=(LL)t*p,ans=(LL)ans*ksm(t%MOD,n/t-n/t/p)%MOD;
	return ans;
}

int main()
{
	scanf("%d%lld",&x,&n);
	int ans=1;
	for (int i=2;i*i<=x;i++)
		if (x%i==0)
		{
			while (x%i==0) x/=i;
			ans=(LL)ans*calc(i)%MOD;
		}
	if (x>1) ans=(LL)ans*calc(x)%MOD;
	printf("%d\n",ans);
	return 0;
}