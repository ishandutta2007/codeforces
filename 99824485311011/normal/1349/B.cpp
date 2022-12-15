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
int T,n,K,a[100010];
void solve()
{
	scanf("%d%d",&n,&K);
	bool f=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),f|=(a[i]==K);
	if(!f)
	{
		puts("no");
		return;
	}
	if(n==1)
	{
		puts("yes");
		return;
	}
	f=0;
	for(int i=1;i<n;i++)
	{
		if(a[i]>=K)
		{
			if(a[i+1]>=K)
			{
				f=1;
				break;
			}
			else if(i!=n-1&&a[i+2]>=K)
			{
				f=1;
				break;
			}
		}
	}
	puts(f?"yes":"no");
}
int main()
{
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}