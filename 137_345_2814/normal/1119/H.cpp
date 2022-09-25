#include<cstdio>
using namespace std;
#define mod 998244353
int f[1050000],n,m,k,s[15],v[15],g[1025],lbit[1025],v2[1025],h[1050000];
int pw(int a,int p){int as=1;while(p){if(p&1)as=1ll*as*a%mod;a=1ll*a*a%mod;p>>=1;}return as;}
int main()
{
	scanf("%d%d",&n,&m);k=3;
	for(int i=1;i<=k;i++)scanf("%d",&s[i]),v2[0]=(v2[0]+s[i])%mod;
	for(int j=1;j<1<<k;j++)
	for(int l=k;l>0;l--)if(j&(1<<l-1))lbit[j]=l;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)scanf("%d",&v[j]);
		g[0]=0;
		for(int j=1;j<1<<k;j++)g[j]=g[j^(1<<lbit[j]-1)]^v[lbit[j]];
		for(int j=0;j<1<<k;j++)f[(g[j]<<k)|j]++;
	}
	for(int l=2;l<=1<<m+k;l<<=1)
	for(int j=0;j<1<<m+k;j+=l)
	for(int s=j;s<j+(l>>1);s++)
	{
		int v1=f[s],v2=f[s+(l>>1)];
		f[s]=(v1+v2)%mod;
		f[s+(l>>1)]=(v1-v2+mod)%mod;
	}
	int inv=1;
	for(int i=1;i<=k;i++)inv=1ll*inv*(mod+1)/2%mod;
	for(int j=1;j<1<<k;j++)v2[j]=(v2[j^(1<<lbit[j]-1)]-2ll*s[lbit[j]]+2ll*mod)%mod;
	for(int i=0;i<1<<m;i++)
	{
		int as1=1;
		for(int j=0;j<1<<k;j++)
		as1=1ll*pw(v2[j],1ll*f[(i<<k)|j]*inv%mod)*as1%mod;
		h[i]=as1;
	}
	for(int l=2;l<=1<<m;l<<=1)
	for(int j=0;j<1<<m;j+=l)
	for(int s=j;s<j+(l>>1);s++)
	{
		int v1=h[s],v2=h[s+(l>>1)];
		h[s]=1ll*(mod+1)/2*(v1+v2)%mod;
		h[s+(l>>1)]=1ll*(mod+1)/2*(v1-v2+mod)%mod;
	}
	for(int i=0;i<1<<m;i++)printf("%d ",(h[i]+mod)%mod);
}