#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const LL N=100005;
LL n;
struct qq
{
	LL x,y;
}s[N];
LL mul (LL x,LL y,LL z)
{
	LL x1=s[x].x-s[z].x,y1=s[x].y-s[z].y;
	LL x2=s[y].x-s[z].x,y2=s[y].y-s[z].y;
	return x1*y2-x2*y1;
}
int main()
{
	scanf("%I64d",&n);
	for (LL u=1;u<=n;u++)	scanf("%I64d%I64d",&s[u].x,&s[u].y);
	LL x=0,y;
	for (LL u=3;u<=n;u++)
		if (mul(2,u,1)!=0)
			{x=u;break;}
	if (x==0)	{printf("YES\n");return 0;}
	/*1,2*/
	y=-1;
	bool tf=true;
	bool ans=false;
	for (LL u=3;u<=n;u++)
	{
		if (mul(2,u,1)==0) continue;
		if (x==u) continue;
		if (y==-1) y=u;
		else
		{
			if (mul(y,u,x)!=0)
			{
				tf=false;
				break;
			}
		}
	}
	ans|=tf;
	/*1,x*/
	tf=true;y=-1;
	for (LL u=3;u<=n;u++)
	{
		if (mul(x,u,1)==0) continue;
		if (y==-1) y=u;
		else
		{
			if (mul(y,u,2)!=0)
			{
				tf=false;
				break;
			}
		}
	}
	ans|=tf;
	/*2,x*/
	y=-1;tf=true;
	for (LL u=3;u<=n;u++)
	{
		if (mul(2,u,x)==0) continue;
		if (y==-1) y=u;
		else
		{
			if (mul(y,u,1)!=0)
			{
				tf=false;
				break;
			}
		}
	}
	ans|=tf;
	if (ans==false) printf("NO\n");
	else printf("YES\n");
	return 0;
}