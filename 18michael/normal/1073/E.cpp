#include<bits/stdc++.h>
#define Mx 1024
#define LL long long
#define mod 998244353
using namespace std;
int K,t;
LL l,r,res;
int one[1024];
LL f[19][1024][2],g[19][1024][2];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline LL calc(LL x)
{
	LL ans=0;
	for(t=0,res=1;res<=x;)res*=10,++t;
	for(int i=0;i<=t;++i)
		for(int j=0;j<Mx;++j)
			f[i][j][0]=f[i][j][1]=g[i][j][0]=g[i][j][1]=0;
	f[t][0][1]=1;
	for(int i=t,w;i;--i)
	{
		res/=10,w=x/res,x%=res;
		for(int j=0,j1;j<Mx;++j)
		{
			for(int k=0;k<=9;++k)
			{
				j1=((!j && !k)? 0:(j|(1<<k)));
				f[i-1][j1][0]=(f[i-1][j1][0]+f[i][j][0])%mod;
				g[i-1][j1][0]=(g[i-1][j1][0]+g[i][j][0]*10+f[i][j][0]*k)%mod;
			}
			for(int k=0;k<w;++k)
			{
				j1=((!j && !k)? 0:(j|(1<<k)));
				f[i-1][j1][0]=(f[i-1][j1][0]+f[i][j][1])%mod;
				g[i-1][j1][0]=(g[i-1][j1][0]+g[i][j][1]*10+f[i][j][1]*k)%mod;
			}
			j1=((!j && !w)? 0:(j|(1<<w)));
			f[i-1][j1][1]=(f[i-1][j1][1]+f[i][j][1])%mod;
			g[i-1][j1][1]=(g[i-1][j1][1]+g[i][j][1]*10+f[i][j][1]*w)%mod;
		}
	}
	for(int i=0;i<Mx;++i)
		if(one[i]<=K)
			ans=(ans+g[0][i][0]+g[0][i][1])%mod;
	return ans;
}
int main()
{
	for(int i=1;i<Mx;++i)one[i]=one[(i>>1)]+(i&1);
	read(l),read(r),read(K);
	return 0&printf("%lld",(calc(r)-calc(l-1)+mod)%mod);
}