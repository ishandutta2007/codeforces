#include<cstdio>
using namespace std;
#define N 1505
#define M 100050
#define mod 1000000007
int fr[M],ifr[M],dpl[N][N],dpr[N][N],sul[N][N],sur[N][N],n,m,a,b,p,k,su=1,su1[N],p1[M],p2[M];
int pw(int a,int p){int as=1;while(p){if(p&1)as=1ll*as*a%mod;a=1ll*a*a%mod;p>>=1;}return as;}
int main()
{
	scanf("%d%d%d%d%d",&n,&m,&a,&b,&k);p=1ll*a*pw(b,mod-2)%mod;
	fr[0]=ifr[0]=p1[0]=p2[0]=1;for(int i=1;i<=k;i++)fr[i]=1ll*fr[i-1]*i%mod,ifr[i]=pw(fr[i],mod-2),p1[i]=1ll*p1[i-1]*p%mod,p2[i]=1ll*p2[i-1]*(mod-p+1)%mod;
	dpl[0][m]=dpr[0][1]=sul[0][m]=sur[0][1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)if(k-j+1>=0)
		dpl[i][j]=(dpl[i][j-1]+1ll*sul[i-1][j-1]*fr[k]%mod*ifr[j-1]%mod*ifr[k-j+1]%mod*p1[j-1]%mod*p2[k-j+1])%mod,su1[j]=(su1[j-1]+1ll*fr[k]*ifr[j-1]%mod*ifr[k-j+1]%mod*p1[j-1]%mod*p2[k-j+1])%mod;
		else dpl[i][j]=dpl[i][j-1],su1[j]=su1[j-1];
		for(int j=1;j<=m;j++)if(k-m+j>=0)
		dpl[i][j]=(1ll*(su-sur[i-1][j+1])*fr[k]%mod*ifr[m-j]%mod*ifr[k-m+j]%mod*p1[m-j]%mod*p2[k-m+j]%mod*su1[j]%mod-1ll*dpl[i][j]*fr[k]%mod*ifr[m-j]%mod*ifr[k-m+j]%mod*p1[m-j]%mod*p2[k-m+j]%mod+mod)%mod;
		for(int j=1;j<=m;j++)sul[i][j]=(sul[i][j-1]+dpl[i][j])%mod;
		for(int j=m;j>=1;j--)if(k-m+j>=0)dpr[i][j]=(dpr[i][j+1]+1ll*sur[i-1][j+1]*fr[k]%mod*ifr[m-j]%mod*ifr[k-m+j]%mod*p1[m-j]%mod*p2[k-m+j])%mod,su1[j]=(su1[j+1]+1ll*fr[k]*ifr[m-j]%mod*ifr[k-m+j]%mod*p1[m-j]%mod*p2[k-m+j])%mod;
		else dpr[i][j]=dpr[i][j+1],su1[j]=su1[j+1];
		for(int j=m;j>=1;j--)if(k-j+1>=0)dpr[i][j]=(1ll*(su-sul[i-1][j-1])*fr[k]%mod*ifr[j-1]%mod*ifr[k-j+1]%mod*p1[j-1]%mod*p2[k-j+1]%mod*su1[j]%mod-1ll*dpr[i][j]*fr[k]%mod*ifr[j-1]%mod*ifr[k-j+1]%mod*p1[j-1]%mod*p2[k-j+1]%mod+mod)%mod;
		for(int j=m;j>=1;j--)sur[i][j]=(sur[i][j+1]+dpr[i][j])%mod;
		su=sur[i][1];
	}
	printf("%d\n",(su+mod)%mod);
}