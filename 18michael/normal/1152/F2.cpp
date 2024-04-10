#include<bits/stdc++.h>
#define LL long long
#define mod 1000000007
using namespace std;
int n,k,m,s,t,Mx;
LL fz,fm,ans=0;
int one[16];
LL f[1002][14][16];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
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
	read(n),read(k),read(m),Mx=(1<<m),t=min(n,(s=m*(k-1)+1)+k),f[0][0][0]=1;for(int i=1;i<Mx;++i)one[i]=one[i>>1]+(i&1);
	for(int i=0;i<t;++i)for(int j=0;j<=k;++j)for(int o=0;o<Mx;++o)(f[i+1][j][(o>>1)]+=f[i][j][o])%=mod,(f[i+1][j+1][(o>>1)|(1<<(m-1))]+=f[i][j][o]*(one[o]+1))%=mod;
	if(t==n){for(int i=1;i<Mx;++i)(f[n][k][0]+=f[n][k][i])%=mod;return 0&printf("%lld",f[n][k][0]);}
	for(int i=m*(k-1)+1;i<=t;++i)for(int j=1;j<Mx;++j)(f[i][k][0]+=f[i][k][j])%=mod;
	for(int i=s;i<=t;++i){fz=f[i][k][0],fm=1;for(int j=s;j<=t;++j)if(i!=j)(fz*=(n-j))%=mod,(fm*=(i-j))%=mod;(ans+=fz*Pow(fm,mod-2))%=mod;}
	return 0&printf("%lld",ans);
}