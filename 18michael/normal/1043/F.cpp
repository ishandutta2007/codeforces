#include<cstdio>
#define Mx 300000
#define LL long long
#define mod 998244353
int n,t=0;
int a[300002],cnt[300002]={};
LL fac[300002],inv[300002];
LL f[8][300002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int gcd(int x,int y)
{
	return y? gcd(y,x%y):x;
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
	fac[0]=1;for(int i=1;i<=n;++i)fac[i]=(fac[i-1]*i)%mod;
	inv[n]=Pow(fac[n],mod-2);for(int i=n;i;--i)inv[i-1]=(inv[i]*i)%mod;
}
inline LL C(int a,int b)
{
	if(a<b)return 0;
	return (((fac[a]*inv[b])%mod)*inv[a-b])%mod;
}
int main()
{
	read(n),init();
	for(int i=1;i<=n;++i)read(a[i]),t=gcd(t,a[i]),++cnt[a[i]];
	if(t>1)return 0&puts("-1");
	for(int i=1;i<=Mx;++i)for(int j=2*i;j<=Mx;j+=i)cnt[i]+=cnt[j];
	for(int i=1;i<=7;++i)
	{
		for(int j=1;j<=Mx;++j)f[i][j]=C(cnt[j],i);
		for(int j=Mx;j;--j)for(int k=2*j;k<=Mx;k+=j)f[i][j]=(f[i][j]-f[i][k])%mod;
		if(f[i][1])return 0&printf("%d",i);
	}
}