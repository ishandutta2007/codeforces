#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
typedef long long LL;
const LL N=1005;
LL n;
LL a[N];
LL mul (LL x1,LL y1,LL x2,LL y2,LL x3,LL y3)
{
	LL x=x3-x1,y=y3-y1;
	LL xx=x2-x1,yy=y2-y1;
	return x*yy-xx*y;
}
int main()
{
	scanf("%lld",&n);
	for (LL u=1;u<=n;u++)	scanf("%lld",&a[u]);
	
	LL k=a[2]-a[1],b=a[1]-k;
	LL X=-1,Y=-1;
	for (LL u=3;u<=n;u++)
		if (k*u+b!=a[u])
		{
			if (X==-1) X=u;
			else 
			{
				Y=u;
				break;
			}
		}
	if (X==-1) 
	{
		printf("No\n");
		return 0;
	}
	if (Y==-1)
	{
		printf("Yes\n");
		return 0;
	}
	bool ok=false;
	for (LL u=4;u<=n;u++)
		if (mul(2,a[2],3,a[3],u,a[u])!=0) ok=true;
	if (!ok)
	{
		printf("Yes\n");
		return 0;
	}
	/*1,2*/
	if ((a[Y]-a[X])==k*(Y-X)) 
	{
		LL k1=k,b1=b;
		LL k2=k,b2=a[X]-k*X;
		bool tf=false;
		for (LL u=1;u<=n;u++)
		{
			if (k1*u+b1==a[u]) continue;
			if (k2*u+b2==a[u]) continue;
			tf=true;
		}
		if (tf==false)
		{
			printf("Yes\n");
			return 0;
		}
	}
	/*1,2*/
	/*1,X*/
	Y=-1;
	for (LL u=3;u<=n;u++)
	{
		if (mul(1,a[1],X,a[X],u,a[u])!=0)
		{
			Y=u;
			break;
		}
	}
	if (Y==-1) {printf("Yes\n");return 0;}
	if ((a[Y]-a[2])*(X-1)==(a[X]-a[1])*(Y-2))
	{
	
	bool tf=false;
	for (LL u=1;u<=n;u++)
	{
		if (mul(1,a[1],X,a[X],u,a[u])==0) continue;
		if (mul(2,a[2],Y,a[Y],u,a[u])==0) continue;
		tf=true;
	}
	if (tf==false)
	{
		printf("Yes\n");
		return 0;
	}
	}
	/*1,X*/
	/*2,X*/
	Y=-1;
	for (LL u=3;u<=n;u++)
	{
		if (mul(2,a[2],X,a[X],u,a[u])!=0)
		{
			Y=u;
			break;
		}
	}
	if ((a[Y]-a[1])*(X-2)!=(a[X]-a[2])*(Y-1)) {printf("No\n");return 0;}
	if (Y==-1) {printf("Yes\n");return 0;}
	bool tf=false;
	for (LL u=1;u<=n;u++)
	{
		if (mul(1,a[1],Y,a[Y],u,a[u])==0) continue;
		if (mul(2,a[2],X,a[X],u,a[u])==0) continue;
		tf=true;
	}
	if (tf==false)
	{
		printf("Yes\n");
		return 0;
	}
	/*2,X*/
	printf("No\n");
	return 0;
}