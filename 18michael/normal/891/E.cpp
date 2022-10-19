#include<cstdio>
#define LL long long
#define mod 1000000007
int n,k,e;LL t,ans=0,res,inv,mul=1;
LL a[5002],c[5002]={};
inline int min(int x,int y)
{
	return x<y? x:y;
}
inline LL pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
int main()
{
	scanf("%d%d",&n,&k),e=min(n,k),t=inv=pow(n,mod-2),c[n]=1;
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
		for(int j=n-i;j<n;++j)c[j]=(c[j+1]*a[i]-c[j])%mod;
		c[n]=-c[n];
	}
	for(int i=1;i<=e;++i,t=(t*inv)%mod)
	{
		res=t;
		for(int j=k-i+1;j<=k;++j)res=(res*j)%mod;
		ans=(ans-c[i]*res)%mod;
	}
	printf("%lld",(ans+mod)%mod);
	return 0;
}