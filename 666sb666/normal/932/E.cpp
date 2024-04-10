#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5005,mod=1e9+7;
inline LL powmod(LL a,LL b){LL c=1;while(b){if(b&1)c=c*a%mod;a=a*a%mod;b>>=1;}return c;}
inline LL inv(LL x){return powmod(x,mod-2);}
int n,k;
LL fac[N],caf[N],facn[N],s[N][N];
int main()
{
	scanf("%d%d",&n,&k);
	s[0][0]=1;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=i;j++)s[i][j]=(s[i-1][j-1]+s[i-1][j]*j)%mod;
	fac[0]=1;for(int i=1;i<=k;i++)fac[i]=fac[i-1]*i%mod;
	caf[k]=inv(fac[k]);for(int i=k-1;i>=0;i--)caf[i]=caf[i+1]*(i+1)%mod;
	facn[0]=1;for(int i=1;i<=k;i++)facn[i]=facn[i-1]*(n-i+1)%mod;
	LL ans=0;
	for(int i=1;i<=min(n,k);i++)ans=(ans+s[k][i]*fac[i]%mod*powmod(2,n-i)%mod*facn[i]%mod*caf[i]%mod)%mod;
	printf("%lld\n",ans);
	return 0;
}