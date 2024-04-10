#include<bits/stdc++.h>
using namespace std;
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
int n,r[110],b[110];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&r[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	int v1=0,v2=0;
	for(int i=1;i<=n;i++)
	{
		if(r[i]&&!b[i])v1++;
		else if(!r[i]&&b[i])v2++;
	}
	if(!v1)puts("-1");
	else printf("%d\n",v2/v1+1);
	return 0;
}