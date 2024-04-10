#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

int tot;
LL n,b,a[105],c[105];

void divi(LL n)
{
	for (LL i=2;i*i<=n;i++)
		if (n%i==0)
		{
			a[++tot]=i;
			while (n%i==0) n/=i,c[tot]++;
		}
	if (n>1) a[++tot]=n,c[tot]=1;
}

int main()
{
	scanf("%lld%lld",&n,&b);
	divi(b);
	LL ans=(LL)1e18;
	for (int i=1;i<=tot;i++)
	{
		LL s=0,t=n;
		while (t>=a[i]) s+=t/a[i],t/=a[i];
		ans=std::min(ans,s/c[i]);
	}
	printf("%lld\n",ans);
	return 0;
}