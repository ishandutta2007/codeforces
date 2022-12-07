#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<bitset>
using namespace std;
typedef unsigned int _int;
typedef long long LL;
bitset<100000000> f;
LL n;
_int a,b,c,d;
_int calc (_int x)// 
{
	//printf("YES:%d\n",x);
	_int lalal=0;
	LL t=1,w=1;
	_int sum=a*x*x*x+b*x*x+c*x+d;
	while (true)
	{
		w=w*x;
		if (w>n) break;
		int a=n/w;//
		lalal=lalal+t*(a-a/x)*sum;
		t++;
	}
	return lalal;
}
int main()
{
	scanf("%u%u%u%u%u",&n,&a,&b,&c,&d);
	for (int u=2;u<=n;u++)
	{
		int a=u%6,now=a;
		if (a!=1&&a!=5) continue;
		if (a==1)
		{
			if (u>6&&f[(u/6-1)*2]==true) continue;
		}
		else
		{
			if (u>6&&f[(u/6-1)*2+1]==true) continue;
		}
		for (int i=u+u;i<=n;i+=u)
		{
			now=now+a;
			if (now>=6) now-=6;
			if (now==1||now==5)
			{
				if (now==1) f[(i/6-1)*2]=true;
				else f[(i/6-1)*2+1]=true;
			}
		}
	}
	_int ans=0;
	if (n>=2) ans=ans+calc(2);
	if (n>=3) ans=ans+calc(3);
	if (n>=5) ans=ans+calc(5);
	int now=7;
	for (int u=0;;u+=2)
	{
		if (now>n) break;
		//printf("%d\n",now);
		if (f[u]==false) ans=ans+calc(now);
		now=now+4;
		//printf("%d\n",now);
		if (now>n) break;
		if (f[u+1]==false) ans=ans+calc(now);
		now=now+2;
	}
	printf("%u\n",ans);
	return 0;
}