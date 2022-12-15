#include<bits/stdc++.h>
using namespace std;
#define lc (p<<1)
#define rc ((p<<1)|1)
typedef long long ll;
const int mod=998244353;
inline int add(int a,int b)
{
	if((a+=b)>=mod)a-=mod;
	return a;
}
inline int dec(int a,int b)
{
	if((a-=b)<0)a+=mod;
	return a;
}
inline int mult(int a,int b)
{
	long long t=1ll*a*b;
	if(t>=mod)t%=mod;
	return t;
}
inline int power(int a,int b)
{
	int out=1;
	while(b)
	{
		if(b&1)out=mult(out,a);
		a=mult(a,a);
		b>>=1;
	}
	return out;
}
int n,m,l[100010],p[100010];
int main()
{
	scanf("%d%d",&n,&m);
	long long sum=0;
	for(int i=1;i<=m;i++)
		scanf("%d",&l[i]),sum+=l[i];
	if(sum<n)
	{
		puts("-1");
		return 0;
	}
	int pre=n+1;
	for(int i=m;i>=1;i--)
	{
		p[i]=min(n-l[i]+1,pre-1);
		if(p[i]<=0)
		{
			puts("-1");
			return 0;
		}
		pre=p[i];
	}
	pre=1;
	for(int i=1;i<=m;i++)
	{
		if(p[i]<=pre)break;
		p[i]=pre;
		pre=p[i]+l[i];
	}
	for(int i=1;i<=m;i++)printf("%d ",p[i]);
	return 0;
}