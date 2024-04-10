#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int inv3=333333336;
int n,q,N,fac[3001000],inv[3001000],g[3001000],f[3001000];
int ksm(int x,int y=mod-2){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
int main(){
	scanf("%d%d",&n,&q),N=3*(n+1);
	fac[0]=1;for(int i=1;i<=N;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[N]=ksm(fac[N]);for(int i=N;i;i--)inv[i-1]=1ll*inv[i]*i%mod;
	for(int i=0;i<=3*n;i++)g[i]=1ll*fac[N]*inv[i+1]%mod*inv[N-i-1]%mod;
	for(int i=0;i<=n;i++)(++f[0])%=mod,(f[1]+=3*i)%=mod;
	for(int i=2;i<=3*n;i++)f[i]=1ll*(4ll*mod+g[i]-3ll*f[i-1]-f[i-2])%mod*inv3%mod;
	for(int i=1,x;i<=q;i++)scanf("%d",&x),printf("%d\n",f[x]);
	return 0;
}