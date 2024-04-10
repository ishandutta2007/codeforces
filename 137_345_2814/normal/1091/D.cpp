#include<cstdio>
using namespace std;
#define N 1000500
long long n,fr[N],mod=998244353,tmp=1,ans=0;
long long pw(long long a,long long p){long long ans=1;while(p){if(p&1)ans=ans*a%mod;a=a*a%mod;p>>=1;}return ans;}
int main()
{
	scanf("%lld",&n);fr[0]=1;
	for(int i=1;i<=n;i++)
	fr[i]=fr[i-1]*i%mod;
	ans=fr[n];
	for(int i=n-1;i>=1;i--)
	ans=((ans+fr[n]-fr[n]*pw(fr[n-i],mod-2)%mod)%mod+mod)%mod;
	printf("%lld\n",ans);
}