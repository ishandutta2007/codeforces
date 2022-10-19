#include<cstdio>
#define LL long long
#define mod 1000000007
int n;LL sum=0,ans;
int l[200002],r[200002],len[200002],ilen[200002],p[200002],p1[200002];
inline int min(int x,int y)
{
	return x<y? x:y;
}
inline int max(int x,int y)
{
	return x>y? x:y;
}
inline LL Pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=Pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
int main()
{
	scanf("%d",&n),ans=(1LL*n*n)%mod,p[1]=p[n+1]=0;
	for(int i=1;i<=n;++i)scanf("%d",&l[i]);
	for(int i=1;i<=n;++i)scanf("%d",&r[i]),ilen[i]=Pow(len[i]=r[i]-l[i]+1,mod-2);
	for(int i=2,x,y;i<=n;++i)
	{
		x=max(l[i-1],l[i]),y=min(r[i-1],r[i]),sum=(sum+(p[i]=(((1LL*max(y-x+1,0)*ilen[i-1])%mod)*ilen[i])%mod))%mod;
		if(i>=3)x=max(x,l[i-2]),y=min(y,r[i-2]),p1[i]=(((((1LL*max(y-x+1,0)*ilen[i-2])%mod)*ilen[i-1])%mod)*ilen[i])%mod;
	}
	for(int i=2;i<=n;++i)
	{
		ans=(((ans-(2LL*n-1)*p[i])%mod)+(sum-p[i-1]-p[i]-p[i+1])*p[i])%mod;
		if(i>=3)ans=(ans+2LL*p1[i])%mod;
	}
	return 0&printf("%lld",(ans+mod)%mod);
}