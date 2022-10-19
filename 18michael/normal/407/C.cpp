#include<cstdio>
#define Mx 100101
#define LL long long
#define mod 1000000007
int n,m;
LL fac[100102],inv[100102];
LL a[102][100102]={};
inline LL Pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=Pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline void init()
{
	fac[0]=1;for(int i=1;i<=Mx;++i)fac[i]=(fac[i-1]*i)%mod;
	inv[Mx]=Pow(fac[Mx],mod-2);for(int i=Mx;i;--i)inv[i-1]=(inv[i]*i)%mod;
}
inline LL C(int a,int b)
{
	if(a<b)return 0;
	return (((fac[a]*inv[b])%mod)*inv[a-b])%mod;
}
int main()
{
	init(),scanf("%d%d",&n,&m);for(int i=1;i<=n;++i)scanf("%lld",&a[0][i]);
	for(int i=1,l,r,k;i<=m;++i)
	{
		scanf("%d%d%d",&l,&r,&k),a[k+1][l]=(a[k+1][l]+1)%mod;
		for(int j=0;j<=k;++j)a[j+1][r+j+1]=(a[j+1][r+j+1]-C(r+1-l+k,k-j))%mod;
	}
	for(int i=101;i;--i)
	{
		for(int j=1;j<=n;++j)a[i][j]=(a[i][j-1]+a[i][j])%mod;
		for(int j=1;j<=n;++j)a[i-1][j]=(a[i-1][j]+a[i][j])%mod;
	}
	for(int i=1;i<=n;++i)printf("%lld%c",(a[0][i]+mod)%mod,i==n? '\n':' ');
	return 0;
}