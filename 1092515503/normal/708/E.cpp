#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int ksm(int x,int y=mod-2){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
int n,m,p,P[1510],K,fac[100100],inv[100100],f[1510],g[1510],r[1510];
int s[1510],t[1510];
int C(int x,int y){if(x<y)return 0;return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;} 
int main(){
	scanf("%d%d%d%d",&n,&m,&p,&K),p=1ll*p*ksm(K)%mod,scanf("%d",&K);
	fac[0]=1;for(int i=1;i<=K;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[K]=ksm(fac[K]);for(int i=K;i;i--)inv[i-1]=1ll*inv[i]*i%mod;
//	printf("%d\n",p);
	for(int i=0;i<m;i++)if(i<=K)P[i]=1ll*C(K,i)*ksm(p,i)%mod*ksm(mod+1-p,K-i)%mod;
	for(int l=1;l<=m;l++)for(int r=l;r<=m;r++)f[r]=(1ll*P[l-1]*P[m-r]+f[r])%mod;
	for(int i=1;i<=m;i++)(f[i]+=f[i-1])%=mod;
	for(int i=0;i<=m;i++)r[i]=f[i];
	for(int i=2;i<=n;i++){
		for(int j=0;j<=m;j++)swap(f[j],g[j]);
		for(int j=1;j<=m;j++)s[j]=(1ll*g[j]*P[j]+s[j-1])%mod;
		t[0]=P[0];for(int j=1;j<=m;j++)t[j]=(t[j-1]+P[j])%mod;
//		for(int j=0;j<=m;j++)printf("%d ",g[j]);puts("");
//		for(int j=0;j<=m;j++)printf("%d ",s[j]);puts("");
//		for(int j=0;j<=m;j++)printf("%d ",t[j]);puts("");
		int S=0,T=0;
		for(int j=0;j<=m;j++){
			f[j]=(1ll*r[j]*g[m]+mod-S+mod-T)%mod;
			S=(1ll*s[j]*P[m-j-1]+S)%mod;
			T=(1ll*t[j]*P[m-j-1]%mod*g[m-j-1]+T)%mod;
		}
	}
//	for(int j=0;j<=m;j++)printf("%d ",f[j]);puts("");
	printf("%d\n",f[m]);
	return 0;
}