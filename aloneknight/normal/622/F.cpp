#include<bits/stdc++.h>
using namespace std;
const int N=1000100,mod=1e9+7;
long long n,k,f[N],fac[N];
long long pw(long long a,long long b){long long res=1;for(;b;b>>=1,a=a*a%mod)if(b&1)res=res*a%mod;return res;}
int main()
{
	scanf("%I64d%I64d",&n,&k);
	for(int i=1;i<=k+2;i++)f[i]=(f[i-1]+pw(1ll*i,k))%mod;
	fac[0]=1;
	for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%mod;
	if(n<=k+2){printf("%I64d\n",f[n]);return 0;}
	long long cc=1,ans=0;
	for(int i=1;i<=k+2;i++)cc=cc*(n-i)%mod;
	for(int i=1;i<=k+2;i++)
	{
		long long t1=pw(n-i,mod-2),t2=pw(fac[i-1]*fac[k+2-i]%mod,mod-2);
		int ff=(k+2-i)%2?-1:1;
		ans=(ans+ff*cc*t1%mod*t2%mod*f[i]%mod)%mod;
	}
	printf("%d\n",(ans+mod)%mod);
	return 0;
}