#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int N=3000;
int ksm(int x,int y=mod-2){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
int n,d[310],f[1010][1010],fac[3010],inv[3010],INV[3010],g[1010][1010],h[1010],hh[1010],sone[1010],stwo[1010],u[310][310][310];
int C(int x,int y){return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;}
//g:ways of i 2s and 2*j 1s forming a graph
//h:ways of i 2s forming a graph 
//#define RANDOM
int main(){
//	freopen("graph.in","r",stdin);
//	freopen("graph.out","w",stdout);
	fac[0]=1;for(int i=1;i<=N;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[N]=ksm(fac[N]);for(int i=N;i>=0;i--)inv[i-1]=1ll*inv[i]*i%mod;
	for(int i=1;i<=N;i++)INV[i]=1ll*fac[i-1]*inv[i]%mod;
	scanf("%d",&n);
	for(int i=3;i<=n;i++)hh[i]=1ll*INV[i]*INV[2]%mod;
	h[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)(h[i]+=1ll*j*hh[j]%mod*h[i-j]%mod)%=mod;
		h[i]=1ll*h[i]*INV[i]%mod;
	}
	for(int i=1;i<=n;i++)h[i]=1ll*h[i]*fac[i]%mod;
//	for(int i=1;i<=n;i++)printf("%d ",h[i]);puts("");
	
	g[0][0]=1;
	for(int i=0;i<=n;i++)for(int j=1;j<=n;j++)for(int k=0;k<=i;k++)(g[i][j]+=1ll*g[i-k][j-1]*fac[i]%mod*inv[i-k]%mod*(2*j-1)%mod)%=mod;
//	for(int i=0;i<=n;i++){for(int j=0;j<=n;j++)printf("%d ",g[i][j]);puts("");}
	for(int i=n;i>=0;i--)for(int j=0;j<=n;j++)for(int k=1;k<=i;k++)(g[i][j]+=1ll*g[i-k][j]*C(i,k)%mod*h[k]%mod)%=mod;
//	for(int i=0;i<=n;i++){for(int j=0;j<=n;j++)printf("%d ",g[i][j]);puts("");}
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		sone[i]=sone[i-1],stwo[i]=stwo[i-1];
		if(d[i]==2)sone[i]++;else stwo[i]++;
	}
	for(int l=0;l<=n;l++)for(int r=0;r<=n;r++)for(int i=0;i<=l;i++)for(int j=0;j<=r;j++)for(int k=0;j+k<=r;k++){
		if((i+k)&1)continue;
		int p=(l-i)+2*(r-j)-k;
		(u[l][r][p]+=1ll*C(l,i)%mod*C(r,j)%mod*C(r-j,k)%mod*g[j][(i+k)/2]%mod*fac[p]%mod*ksm(INV[2],r-j-k)%mod)%=mod;
	}
	f[1][d[1]+1]=1;
	for(int r=1;r<=n;r++)for(int l=1;l<r;l++){
		if(!f[l][r])continue;
		int one=sone[r]-sone[l],two=stwo[r]-stwo[l];
		for(int p=0;p<=n;p++)(f[r][r+p]+=1ll*f[l][r]*u[one][two][p]%mod)%=mod;
	}
	printf("%d\n",f[n][n]);
	return 0;
} 
/*
10
3 2 2 2 2 2 2 2 2 3
*/