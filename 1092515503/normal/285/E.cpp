#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m,f[1010][1010][2][2],fac[1010],inv[1010],F[1010],res;
int ksm(int x,int y){
	int z=1;
	for(;y;y>>=1,x=(1ll*x*x)%mod)if(y&1)z=(1ll*z*x)%mod;
	return z;
}
int C(int x,int y){
	return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main(){
	scanf("%d%d",&n,&m),f[1][0][0][0]=f[1][1][0][1]=1;
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=(1ll*fac[i-1]*i)%mod;
	inv[n]=ksm(fac[n],mod-2);
	for(int i=n-1;i>=0;i--)inv[i]=(1ll*inv[i+1]*(i+1))%mod;
	for(int i=2;i<=n;i++)for(int j=0;j<=i;j++){
		if(j){
			f[i][j][0][0]=f[i-1][j-1][0][0];
			f[i][j][1][0]=f[i-1][j-1][0][1];
			if(i<n)f[i][j][0][1]=(f[i-1][j-1][0][0]+f[i-1][j-1][1][0])%mod;
			if(i<n)f[i][j][1][1]=(f[i-1][j-1][0][1]+f[i-1][j-1][1][1])%mod;
		}
		f[i][j][0][0]=(0ll+f[i][j][0][0]+f[i-1][j][0][0]+f[i-1][j][1][0])%mod;
		f[i][j][1][0]=(0ll+f[i][j][1][0]+f[i-1][j][0][1]+f[i-1][j][1][1])%mod;
	} 
	for(int i=0;i<=n;i++)F[i]=1ll*fac[n-i]*(f[n][i][0][0]+f[n][i][1][0])%mod;
	for(int i=m;i<=n;i++)(res+=(((i-m)&1?-1ll:1ll)*(1ll*C(i,m)*F[i]%mod)+mod)%mod)%=mod;
	printf("%d\n",res);
	return 0;
}