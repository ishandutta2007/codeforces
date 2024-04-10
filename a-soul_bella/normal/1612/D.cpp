#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int gcd(int n,int m)
{
	while(n^=m^=n^=m%=n);
	return m;
}
bool findkx(int n,int m,int x)
{
	if(n<m)swap(n,m);
	if(m==0&&n==x)return true;
	if(m==0&&n!=x)return false;
	if((n-x)%m==0&&x<=n)return true;
	return findkx(n%m,m,x);
}
signed main()
{
	int t,a,b,x,sth;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		a=read();
		b=read();
		x=read();
		sth=gcd(a,b);
		if(x%sth!=0)
		{
			printf("NO\n");
			continue;
		}
		a/=sth;
		b/=sth;
		x/=sth;
		if(findkx(a,b,x))printf("YES\n");
		else printf("NO\n");
	}
}