#include<bits/stdc++.h>
#define LL long long
#define mod 1000000007
using namespace std;
int n,N=0,Mx=100000;
LL res=0;
int a[2502],f[100002];
LL fac[100002],inv[100002];
inline LL Pow(int a,int b)
{
	if(!b)return 1;
	LL c=Pow(a,b>>1);
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),N+=a[i];
	fac[0]=1;
	for(int i=1;i<=Mx;++i)
	{
		if(N-i+1)fac[i]=(fac[i-1]*(N-i+1))%mod;
		else fac[i]=fac[i-1];
	}
	inv[Mx]=Pow(fac[Mx],mod-2);
	for(int i=Mx;i;--i)
	{
		if(N-i+1)inv[i-1]=(inv[i]*(N-i+1))%mod;
		else inv[i-1]=inv[i];
	}
	for(int i=1;i<=Mx;++i)(res+=(inv[i]*fac[i-1]))%=mod,f[i]=(((res*(N-1))%mod)*(N-i))%mod;
	res=0;
	for(int i=1;i<=n;++i)(res+=f[a[i]])%=mod;
	return 0&printf("%lld",(res+mod)%mod);
}