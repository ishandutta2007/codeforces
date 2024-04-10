#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int ksm(int x,int y=mod-2){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
int n,m,L[2010],R[2010],f[2][2010][4010],fac[4010],inv[4010],res;
int main(){
	scanf("%d%d",&n,&m);
	fac[0]=1;for(int i=1;i<=(n<<1|1);i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[n<<1|1]=ksm(fac[n<<1|1]);for(int i=n<<1|1;i;i--)inv[i-1]=1ll*inv[i]*i%mod;
	for(int i=1,x;i<=n;i++)scanf("%d",&x),L[i]=max(x-m,0),R[i]=min(x+m,n+1);
	L[0]=R[0]=0;
	f[0][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=L[i];j<=R[i];j++)for(int k=0;k<=n;k++)f[i&1][j][j+k]=0;
		for(int j=L[i-1];j<=R[i-1];j++)for(int k=j;k<=j+n;k++)if(f[!(i&1)][j][k])
			(f[i&1][max(j+1,L[i])][k+1]+=1ll*f[!(i&1)][j][k]*fac[k-j]%mod)%=mod,
			(f[i&1][max(k+2,L[i])][k+1]+=mod-1ll*f[!(i&1)][j][k]*fac[k-j]%mod)%=mod;
		for(int j=L[i]+1;j<=R[i];j++)for(int k=j;k<=j+n;k++)
			(f[i&1][j][k]+=f[i&1][j-1][k])%=mod;
		for(int j=L[i];j<=R[i];j++)for(int k=j;k<=j+n;k++)
			f[i&1][j][k]=1ll*f[i&1][j][k]*inv[k-j]%mod;
		for(int j=L[i-1];j<=R[i-1];j++)for(int k=j;k<=j+n;k++)if(f[!(i&1)][j][k])
			(f[i&1][j][k]+=1ll*f[!(i&1)][j][k]*k%mod)%=mod,
			(f[i&1][j][k+1]+=f[!(i&1)][j][k])%=mod;
//		for(int j=L[i];j<=R[i];j++)for(int k=0;k<=n;k++)
//			printf("[%d,%d,%d]:%d\n",i,j,k,f[i&1][j][j+k]);
	}
	for(int j=L[n];j<=R[n];j++)for(int k=0;k<=n;k++)
		if(k<=max(n-j,0))(res+=1ll*f[n&1][j][j+k]*fac[max(n-j,0)]%mod*inv[max(n-j,0)-k]%mod)%=mod;
	printf("%d\n",res);
	return 0;
}