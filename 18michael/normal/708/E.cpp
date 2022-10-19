#include<bits/stdc++.h>
#define LL long long
#define mod 1000000007
using namespace std;
int n,m,b,k,p;
LL inv[100002],fac[100002],D[1502],preD[1502],preDL[1502];
LL L[1502][1502];
inline LL Pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=Pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline LL C(int a,int b)
{
	if(a<b)return 0;
	return (((fac[a]*inv[b])%mod)*inv[a-b])%mod;
}
inline void init()
{
	fac[0]=L[0][m+1]=1;for(int i=1;i<=k;++i)fac[i]=(fac[i-1]*i)%mod;
	inv[k]=Pow(fac[k],mod-2);for(int i=k;i;--i)inv[i-1]=(inv[i]*i)%mod;
	for(int i=0;i<=m;++i)preD[i]=((i? preD[i-1]:0)+(D[i]=(i<=k? (((C(k,i)*Pow(p,i))%mod)*Pow(1-p,k-i))%mod:0)))%mod;
}
int main()
{
	scanf("%d%d%d%d%d",&n,&m,&p,&b,&k),p=(Pow(b,mod-2)*p)%mod,init();
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m+1;++j)preDL[j]=(preDL[j-1]+D[j-1]*L[i-1][j])%mod;
		for(int j=0;j<=m;++j)L[i][j+1]=(D[m-j]*((preD[j-1]*(L[i-1][m+1]-L[i-1][m+1-j])-preDL[j])%mod)+L[i][j])%mod;
	}
	return 0&printf("%lld",(L[n][m+1]+mod)%mod);
}