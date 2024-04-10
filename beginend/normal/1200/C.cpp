#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

LL n,m,n1,m1;
int q;

LL gcd(LL x,LL y)
{
	if (!y) return x;
	else return gcd(y,x%y);
}

LL get(LL x,LL y)
{
	if (x==1) return (y-1)/n1+1;
	else return (y-1)/m1+1;
}

int main()
{
	scanf("%lld%lld%d",&n,&m,&q);
	LL d=gcd(n,m);n1=n/d;m1=m/d;
	while (q--)
	{
		LL x1,y1,x2,y2;
		scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
		if (get(x1,y1)==get(x2,y2)) puts("YES");
		else puts("NO");
	}
	return 0;
}