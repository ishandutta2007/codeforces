#include<bits/stdc++.h>
using namespace std;
#define lc (p<<1)
#define rc ((p<<1)|1)
typedef long long ll;
int mod=998244353;
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
int n,m,a[200010],cnt[1010];
int main()
{
	scanf("%d%d",&n,&m);
	mod=m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
//		a[i]%=m;
		cnt[a[i]%m]++;
	}
	for(int i=0;i<m;i++)
	{
		if(cnt[i]>=2)
		{
			puts("0");
			return 0;
		}
	}
	memset(cnt,0,sizeof(cnt));
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			ans=mult(ans,abs(a[i]-a[j])%m);
		}
	}
	printf("%d\n",ans);
	return 0;
}