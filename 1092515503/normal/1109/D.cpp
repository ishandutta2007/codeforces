#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int ksm(int x,int y=mod-2){if(y<0)y+=mod-1;int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
int n,m,fac[1001000],inv[1001000],res;
int C(int x,int y){if(x<y||x<0)return 0;return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;}
int main(){
	scanf("%d%d",&n,&m);
	fac[0]=1;for(int i=1;i<=max(n,m);i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[max(n,m)]=ksm(fac[max(n,m)]);for(int i=max(n,m);i;i--)inv[i-1]=1ll*inv[i]*i%mod;
	for(int i=min(m+1,n),j=ksm(m,n-i),k=ksm(n,n-i-1);i>=2;i--,j=1ll*j*m%mod,k=1ll*k*n%mod){
		if(i<n)res=(1ll*C(m-1,i-2)*C(n-2,i-2)%mod*fac[i-2]%mod*j%mod*i%mod*k+res)%mod;
		else res=(1ll*C(m-1,i-2)*C(n-2,i-2)%mod*fac[i-2]%mod*j+res)%mod;
	}
	printf("%d\n",res);
	return 0;
}