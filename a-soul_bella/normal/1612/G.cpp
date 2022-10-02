#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
#define mod 1000000007
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
int f[2000005];
int c[1000005];
int jc[1000005];
signed main()
{
	int n;
	n=read();
	for(int i=1;i<=n;i++)c[i]=read();
	for(int i=1;i<=n;i++)
	{
		f[1000000-(c[i]-1)]++;
		f[1000000+(c[i]+1)]--;
	}
	jc[0]=1;
	jc[1]=1;
	for(int i=2;i<=2000000;i++)f[i]+=f[i-2];
	for(int i=2;i<=1000000;i++)jc[i]=jc[i-1]*i%mod;
	int sl=0,ans=0,cj=1;
	for(int i=1;i<=n;i++)sl+=c[i];
	for(int i=2000000;i>=0;i--)
	{
		ans=(ans+(2*sl+mod-f[i]+1)*f[i]/2%mod*(i+mod-1000000)%mod)%mod;
		sl-=f[i];
		cj=1LL*cj*jc[f[i]]%mod;
	}
	printf("%lld %lld\n",ans,cj);
	return 0;
}