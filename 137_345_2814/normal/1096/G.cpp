#include<cstdio>
#include<cstring>
using namespace std;
#define N 5000001
#define mod 998244353
int fft[N],rev[N],ss=3,a[N],n,m,k,s;
inline int pw(int a,long long p){int ans=1;if(p<1)return 1;while(p){if(p&1)ans=1ll*ans*a%mod;a=1ll*a*a%mod;p>>=1;}return ans;}
void dft(int s,int *a,int tmp)
{
	for(int i=0;i<s;i++)
	fft[i]=a[rev[i]];
	for(int i=2;i<=s;i*=2)
	{
		int v1=pw(ss,(mod-1)/i);
		if(tmp==-1)v1=pw(v1,mod-2);
		for(int j=0;j+i<=s;j+=i)
		{
			int v2=1;
			for(int k=j;k<j+(i>>1);k++)
			{
				int s1=fft[k],s2=1ll*fft[k+(i>>1)]*v2%mod;
				fft[k]=(s1+s2)%mod;
				fft[k+(i>>1)]=(s1-s2+mod)%mod;
				v2=1ll*v2*v1%mod;
			}
		}
	}
	for(int i=0;i<s;i++)
	a[i]=fft[i];
	int v=pw(s,mod-2);
	if(tmp==-1)
	for(int i=0;i<s;i++)
	a[i]=1ll*a[i]*v%mod;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
	scanf("%d",&m),a[m]=1;
	n/=2;s=1;
	while(s<=9*n)s*=2;
	for(int i=0;i<=s;i++)rev[i]=(rev[i>>1]>>1)+((i&1)*s/2);
	dft(s,a,1);
	for(int i=0;i<s;i++)
	a[i]=pw(a[i],n);
	dft(s,a,-1);
	long long ans=0;
	for(int i=0;i<=s;i++)
	ans=(ans+1ll*a[i]*a[i])%mod;
	printf("%lld\n",ans);
}