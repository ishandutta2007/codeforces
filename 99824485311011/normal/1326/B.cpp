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
int n,b[200010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	int premx=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i]>=0)
		{
			printf("%d ",premx+b[i]);
			premx+=b[i];
		}
		else
		{
			printf("%d ",premx+b[i]);
		}
	}
	return 0;
}