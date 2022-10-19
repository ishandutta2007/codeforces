#include<bits/stdc++.h>
const int mod=1e9+7;
int n,m,a[1001000],res,prod=1,fac[1001000],inv[1001000];
int ksm(int x,int y){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
int main(){
	scanf("%d%d",&n,&m),fac[0]=1;
	for(int i=1;i<=m+1;i++)a[i]=(ksm(i,m)+a[i-1])%mod,fac[i]=1ll*fac[i-1]*i%mod;
	if(n<=m+1){printf("%d\n",a[n]);return 0;}
	for(int i=0;i<=m+1;i++)prod=1ll*prod*(n-i+mod)%mod;
	inv[m+1]=ksm(fac[m+1],mod-2);
	for(int i=m;i>=0;i--)inv[i]=1ll*inv[i+1]*(i+1)%mod;
	for(int i=0;i<=m+1;i++)(res+=1ll*a[i]*prod%mod*ksm((n-i+mod)%mod,mod-2)%mod*(((m+1-i)&1)?mod-inv[m+1-i]:inv[m+1-i])%mod*inv[i]%mod)%=mod;
	printf("%d\n",res);
	return 0;
}