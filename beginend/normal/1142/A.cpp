#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

LL n,k,a,b,mx,mn;

LL gcd(LL x,LL y)
{
	if (!y) return x;
	else return gcd(y,x%y);
}

void solve(LL w)
{
	LL d=gcd(w,k),x=w/d,y=k/d;
	for (int i=0;i<n;i++)
	{
		LL p=gcd((x+(LL)y*i)%n,n);
		mx=std::max(mx,y*n/p);
		mn=std::min(mn,y*n/p);
	}
}

int main()
{
	scanf("%lld%lld%lld%lld",&n,&k,&a,&b);
	mn=n*k;mx=0;
	int x1=a,x2=k-a,y1=b,y2=k-b;
	solve(abs(x1-y1));
	solve(abs(x1-y2));
	solve(abs(x2-y1));
	solve(abs(x2-y2));
	printf("%lld %lld\n",mn,mx);
	return 0;
}