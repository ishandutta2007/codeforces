#include<bits/stdc++.h>

typedef long long LL;

const int N=105;

int tot;
LL a,m,ans,pri[N];

LL gcd(LL x,LL y)
{
	return !y?x:gcd(y,x%y);
}

LL divi(LL n)
{
	tot=0;
	for (LL i=2;i*i<=n;i++)
		if (n%i==0)
		{
			pri[++tot]=i;
			while (n%i==0) n/=i;
		}
	if (n>1) pri[++tot]=n;
}

void dfs(int x,LL p,int f)
{
	if (x>tot)
	{
		ans+=(LL)f*(m-a%p+p-1)/p;
		return;
	}
	dfs(x+1,p,f);
	dfs(x+1,p*pri[x],-f);
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%lld%lld",&a,&m);
		LL d=gcd(a,m);
		a/=d;m/=d;
		divi(m);
		ans=0;
		dfs(1,1,1);
		printf("%lld\n",ans);
	}
	return 0;
}