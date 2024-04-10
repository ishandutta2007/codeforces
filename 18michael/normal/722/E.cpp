#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define Mx 20
#define Mx1 200000
#define LL long long
#define mod 1000000007
using namespace std;
int n,m,k;
LL ans;
LL fac[200002],inv[200002],s[22],g[22];
LL f[2002][24]={};
struct aaa
{
	int x,y;
}p[2002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(aaa a,aaa b)
{
	return (a.x==b.x)? (a.y<b.y):(a.x<b.x);
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
	fac[0]=1;for(int i=1;i<=Mx1;++i)fac[i]=(fac[i-1]*i)%mod;
	inv[Mx1]=Pow(fac[Mx1],mod-2);for(int i=Mx1;i;--i)inv[i-1]=(inv[i]*i)%mod;
}
inline LL C(int a,int b)
{
	return (((fac[a]*inv[b])%mod)*inv[a-b])%mod;
}
int main()
{
	init(),read(n),read(m),read(k),read(s[0]),g[0]=C(n+m-2,n-1);
	for(int i=1;i<=Mx;++i)s[i]=((s[i-1]+1)>>1);
	for(int i=1;i<=k;++i)read(p[i].x),read(p[i].y);
	sort(p+1,p+k+1,cmp);
	for(int i=1;i<=k;++i)
	{
		f[i][1]=C(p[i].x+p[i].y-2,p[i].x-1);
		for(int j=1;j<i;++j)
			if(p[j].x<=p[i].x && p[j].y<=p[i].y)
				for(int o=0;o<Mx;++o)
					(f[i][o+1]+=f[j][o]*C(p[i].x-p[j].x+p[i].y-p[j].y,p[i].x-p[j].x))%=mod;
		for(int j=0;j<Mx;++j)(f[i][j]-=f[i][j+1])%=mod;
		for(int j=0;j<=Mx;++j)(g[j]+=f[i][j]*C(n-p[i].x+m-p[i].y,n-p[i].x))%=mod;
	}
	for(int i=0;i<=Mx;++i)(ans+=g[i]*s[i])%=mod;
	return 0&printf("%lld",(((ans*Pow(C(n+m-2,n-1),mod-2))%mod)+mod)%mod);
}