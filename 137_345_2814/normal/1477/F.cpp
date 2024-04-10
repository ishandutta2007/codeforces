#include<cstdio>
using namespace std;
#define N 2005
#define M 52
#define mod 998244353
int pw(int a,int p){int as=1;while(p){if(p&1)as=1ll*as*a%mod;a=1ll*a*a%mod;p>>=1;}return as;}
int n,k,v[N],su,s1,v1[N][2],dp[M][N],fr[N],ifr[N],as;
int solve(int a,int b){return 1ll*fr[a]*pw(mod+1-b,mod-2-a)%mod;}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]),su+=v[i];
	fr[0]=ifr[0]=1;for(int i=1;i<=su;i++)fr[i]=1ll*fr[i-1]*i%mod,ifr[i]=pw(fr[i],mod-2);
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		int s2=(v[i]-1)/k;
		for(int j=1;j<=s2;j++)v1[j][0]=1ll*pw(1ll*(v[i]-j*k)*pw(su,mod-2)%mod,j)*ifr[j]%mod,v1[j][1]=1ll*pw(1ll*(v[i]-j*k)*pw(su,mod-2)%mod,j-1)*ifr[j-1]%mod;
		for(int p=i-1;p>=0;p--)
			for(int q=s1;q>=0;q--)
				for(int r=1;r<=s2;r++)
					for(int s=0;s<2;s++)
						dp[p+s][q+r]=(dp[p+s][q+r]+1ll*dp[p][q]*v1[r][s])%mod;
		s1+=s2;
	}
	for(int i=0;i<=n;i++)for(int j=i;j<=s1;j++)as=(as+1ll*dp[i][j]*solve(j-i,1ll*(su-j*k)*pw(su,mod-2)%mod)%mod*(j&1?1:mod-1))%mod;
	printf("%d\n",as);
}