#include<cstdio>
using namespace std;
long long s,v[50];
const int mod=1000000007;
int bitc(int x)
{
	int ans=0;
	while(x)
	{
		ans+=x&1;
		x>>=1;
	}
	return ans;
}
long long pw(long long a,long long p)
{
	long long ans=1;
	while(p)
	{
		if(p&1) ans=ans*a%mod;
		a=a*a%mod;
		p>>=1;
	}
	return ans;
}
int exgcd(int a,int b,long long& x,long long& y)
{
	if(b==0)
	{
		x=1,y=0;
		return a;
	}
	int gcd=exgcd(b,a%b,x,y);
	long long t=x;x=y;y=t-a/b*y;
	return gcd;
}
long long C(long long j,long long i)
{
	if (i<0) return 0;
	long long ans=1,i1=1,i3=1;
	for(int i2=1;i2<=i;i2++)
	i1=i1*(j-i+i2)%mod,i3=i3*i2%mod;
	ans=ans*i1%mod*pw(i3,mod-2)%mod;
	return ans;
}
long long L(long long a,long long b)
{
	if(a<mod&&b<mod)
	return C(a,b);
	return L(a/mod,b/mod)*C(a%mod,b%mod)%mod;
}
int main()
{
	int n;
	scanf("%d%lld",&n,&s);
	for(int i=1;i<=n;i++)
	scanf("%lld",&v[i]);
	long long ans=L(s+n-1,n-1);
	for(int i=1;i<(1<<n);i++)
	{
		long long tmp=0;
		for(int j=1;j<=n;j++)
		if(i&(1<<(j-1)))
		tmp+=v[j]+1;
		if(s-tmp>=0)
		ans=(ans+pw(-1,bitc(i))*L(s-tmp+n-1,n-1))%mod;
	}
	printf("%lld\n",(ans+mod)%mod);
}