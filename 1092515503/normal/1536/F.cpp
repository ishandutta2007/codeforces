#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int ksm(int x,int y=mod-2){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
int n,fac[1001000],inv[1001000],res;
int C(int x,int y){if(y<0||x<y)return 0;return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;}
int main(){
	scanf("%d",&n);
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=ksm(fac[n]);for(int i=n;i;i--)inv[i-1]=1ll*inv[i]*i%mod;
	for(int i=2;i<=n;i+=2)res=(2ll*fac[i]*(C(i,n-i)+C(i-1,n-i-1))+res)%mod;
	printf("%d\n",res);
	return 0;
}