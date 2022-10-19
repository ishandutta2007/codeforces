#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m,fac[1001000],inv[1001000],res;
int ksm(int x,int y=mod-2){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
int C(int x,int y){return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;}
int main(){
	scanf("%d%d",&n,&m);
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=ksm(fac[n]);for(int i=n;i;i--)inv[i-1]=1ll*inv[i]*i%mod;
	for(int i=1,sum=0;i<=m-2&&i<=n;i++){
		int val=1ll*C(n,i)*fac[i]%mod*i%mod;
		res=((2ll*val*sum+1ll*val*val)%mod*ksm(n,m-i-2)+res)%mod;
		(sum+=val)%=mod;
	}
	if(m-1<=n)for(int i=1,j=m-1;i<=m-1;i++){
		int val=1ll*C(n-1,i-1)*C(n-1,j-1)%mod*n%mod*fac[i]%mod*fac[j]%mod;
		(res+=val)%=mod;
		if(i!=j)(res+=val)%=mod;
	}
	int sum0=0,sum1=0;
	for(int j=1;j<m&&j<=n;j++){
		(sum0+=inv[n-j])%=mod;
		(sum1+=1ll*inv[n-j]*j%mod)%=mod;
	}
	for(int i=m;i<=n;i++){
		(res+=(2ll*sum0+inv[n-i])%mod*fac[n]%mod*
		fac[n-(i-m)-1]%mod*inv[n-i]%mod)%=mod;
		(res+=(2ll*sum1+1ll*inv[n-i]*i)%mod*fac[n]%mod*
		fac[n-(i-m)-2]%mod*inv[n-i]%mod*(m-1)%mod)%=mod;
		(res+=(2ll*sum0+inv[n-i])%mod*fac[n]%mod*(m+mod-i-1)%mod*
		fac[n-(i-m)-2]%mod*inv[n-i]%mod*(m-1)%mod)%=mod;
		(sum0+=inv[n-i])%=mod;
		(sum1+=1ll*inv[n-i]*i%mod)%=mod;
	}
	printf("%d\n",res);
	return 0;
}