#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int n,m;
long long a[200009],b[200009],res,flag;
inline long long Gcd(long long x,long long y)
{
	if(y==0)return x;
	else return Gcd(y,x%y);
}
inline long long val(long long x,long long y)
{
	if(x>y)return x-y;
	else return y-x;
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)b[i]=read();
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
		if(a[i]!=a[i-1])
		{
			res=a[i]-a[i-1];flag=1;break;
		}
	if(!flag)
	{
		for(int i=1;i<=m;i++)printf("%lld ",b[i]+a[1]);
		return 0;
	}
	for(int i=2;i<=n;i++)res=Gcd(res,a[i]-a[i-1]);
	res=Gcd(res,a[n]-a[1]);
	for(int i=1;i<=m;i++)printf("%lld ",Gcd(res,b[i]+a[1]));
	return 0;
}