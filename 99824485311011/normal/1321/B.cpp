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
int n,b[200010];
long long f[800010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),f[b[i]-i+400002]+=b[i];
	printf("%lld\n",*max_element(f,f+800010));
	return 0;
}