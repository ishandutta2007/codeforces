#include<cstdio>
#define LL long long
#define mod 998244353
int n,k,k2;
LL ans=0;
int b[2002];
LL fac[2052],inv[2052];
LL f[2][2002][102];//first i numbers, j kinds, mex=b[i]+o-k
struct aaa
{
	int x,y,z;
};
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
inline void init()
{
	fac[0]=1;for(int i=1;i<=n+k;++i)fac[i]=(fac[i-1]*i)%mod;
	inv[n+k]=Pow(fac[n+k],mod-2);for(int i=n+k;i;--i)inv[i-1]=(inv[i]*i)%mod;
}
inline LL C(int a,int b)
{
	if(b<0 || a<b)return 0;
	return (((fac[a]*inv[b])%mod)*inv[a-b])%mod;
}
inline bool check(int x)
{
	return (x>=0 && x<=k2);
}
int main()
{
	scanf("%d%d",&n,&k),k2=(k<<1),b[0]=0,f[0][0][k]=1,init();
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	for(int i=1,i0=0,i1=1;i<=n;++i,i0^=1,i1^=1)
	{
		for(int j=0;j<=i;++j)for(int o=0;o<=k2;++o)f[i1][j][o]=0;
		for(int j=0;j<=i;++j)
			for(int o=0;o<=k2;++o)
			{
				if(check(max(b[i-1]+o+1-b[i],0)))(f[i1][j+1][max(b[i-1]+o+1-b[i],0)]+=f[i0][j][o])%=mod;
				if(check(b[i-1]+o+j+2-b[i]))(f[i1][j+1][b[i-1]+o+j+2-b[i]]-=f[i0][j][o])%=mod;
				//the new number is eqaul to o
			}
		for(int j=0;j<=i;++j)for(int o=1;o<=k2;++o)(f[i1][j][o]+=f[i1][j][o-1])%=mod;
		for(int j=0;j<=i;++j)
			for(int o=0;o<=k2;++o)
			{
				if(check(b[i-1]+o-b[i]))(f[i1][j][b[i-1]+o-b[i]]+=f[i0][j][o]*j)%=mod;
				//the new number has appeared
				if(check(b[i-1]+o-b[i]))(f[i1][j+1][b[i-1]+o-b[i]]+=f[i0][j][o]*(j-b[i-1]-o+k+1))%=mod;
				//the new number hasn't appeared and is in [o+1,n]
			}
	}
	for(int i=1;i<=n;++i)for(int j=0;j<=k2;++j)(ans+=f[n&1][i][j]*C(n-b[n]-j+k,i-b[n]-j+k))%=mod;
	return 0&printf("%lld",(ans+mod)%mod);
}