#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
LL n,a,b;
LL exgcd (LL a,LL b,LL &x,LL &y)
{
	if (a==0)
	{
		x=0;y=1;
		return b;
	}
	LL tx,ty;
	LL d=exgcd(b%a,a,tx,ty);
	y=tx;x=ty-(b/a)*tx;
	return d;
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&a,&b);
	LL x,y;
	LL d=exgcd(a,b,x,y);
	if (n%d!=0) printf("NO\n");
	else
	{
		LL xx=(x*(n/d)%(b/d)+(b/d))%(b/d);
		LL yy=(n-xx*a)/b;
		if (xx<0||yy<0)
		{
			printf("NO\n");
			return 0;
		}
		printf("YES\n");
		printf("%I64d %I64d\n",xx,yy);
	}
	return 0;
}