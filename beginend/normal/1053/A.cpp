#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

int n,m,k;

LL gcd(LL x,LL y)
{
	if (!y) return x;
	else return gcd(y,x%y);
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	LL dd=(LL)k/gcd((LL)n*m,k);
	if (dd>2) {puts("No");return 0;}
	int x=k,p=n,q=m;
	int d=gcd(x,p);
	x/=d;p/=d; 
	d=gcd(x,q);
	x/=d;q/=d;
	puts("Yes");
	printf("%d %d\n",0,0);
	if (x==1)
	{
		if (p<n) printf("%d %d\n%d %d\n",p*2,0,0,q);
		else printf("%d %d\n%d %d\n",p,0,0,q*2);
	}
	else printf("%d %d\n%d %d\n",p,0,0,q);
	return 0;
}