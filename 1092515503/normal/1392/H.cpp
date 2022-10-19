#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int ksm(int x,int y=mod-2){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
int n,m,fac[4001000],inv[4001000],res;
int C(int x,int y){return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;}
int main(){
	scanf("%d%d",&n,&m);
	fac[0]=1;for(int i=1;i<=n+m+1;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[n+m+1]=ksm(fac[n+m+1]);for(int i=n+m+1;i;i--)inv[i-1]=1ll*inv[i]*i%mod;
	for(int k=1;k<=n;k++){
		int f=1ll*(m+k)*ksm(k)%mod;
//		printf("%d\n",f);
		f=1ll*f*C(n,k)%mod;
		if(k&1)(res+=f)%=mod;
		else(res+=mod-f)%=mod; 
	}
	int T=1;
	for(int i=1;i<=n;i++)T=(1ll*T*i%mod*ksm(i+m)+1)%mod;
	printf("%d\n",1ll*res*T%mod);
	return 0;
}