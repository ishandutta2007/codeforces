#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=100005;

int n,tot;
LL ans[N];

int gcd(int x,int y)
{
	if (!y) return x;
	else return gcd(y,x%y);
}

LL get_sum(LL w)
{
	return w*(w+1)/(LL)2;
}

void solve(int m)
{
	int d=gcd(n,m);
	LL w=(LL)get_sum(n/d)*d+(LL)(n/d)-(LL)n;
	ans[++tot]=w;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i*i<=n;i++)
		if (n%i==0)
		{
			solve(i);
			if (n/i!=i) solve(n/i);
		}
	std::sort(ans+1,ans+tot+1);
	tot=std::unique(ans+1,ans+tot+1)-ans-1;
	for (int i=1;i<=tot;i++) printf("%lld ",ans[i]);
	return 0;
}