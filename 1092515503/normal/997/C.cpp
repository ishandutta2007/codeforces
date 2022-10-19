#include<bits/stdc++.h>
using namespace std;
const int N=1<<20;
const int mod=998244353;
int n,fac[N],inv[N],tri[N],ntr[N],itr[N],itn[N];
int ksm(int x,int y){
	if(y<0)y+=mod-1;
	int z=1;
	for(;y;x=1ll*x*x%mod,y>>=1)if(y&1)z=1ll*z*x%mod;
	return z;
}
int main(){
	scanf("%d",&n);
	
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=ksm(fac[n],-1);
	for(int i=n-1;i>=0;i--)inv[i]=1ll*inv[i+1]*(i+1)%mod;
	
	tri[0]=1;
	for(int i=1;i<=n;i++)tri[i]=3ll*tri[i-1]%mod;
	itr[n]=ksm(tri[n],-1);
	for(int i=n-1;i>=0;i--)itr[i]=3ll*itr[i+1]%mod;
	
	ntr[0]=1;
	for(int i=1;i<=n;i++)ntr[i]=1ll*ntr[i-1]*tri[n]%mod;
	itn[n]=ksm(ntr[n],-1);
	for(int i=n-1;i>=0;i--)itn[i]=1ll*itn[i+1]*tri[n]%mod;
	
	int I=0;
	for(int i=1,now;i<=n;i++)now=1ll*fac[n]*inv[i]%mod*inv[n-i]%mod*tri[i]%mod*ntr[n-i]%mod,(I+=(i&1?now:mod-now))%=mod;
	(I<<=1)%=mod;
	
	int II=0;
	for(int i=1,now;i<=n;i++)now=1ll*fac[n]*inv[i]%mod*inv[n-i]%mod*itn[i]%mod*(mod+ksm((mod+1-itr[n-i])%mod,n)-1)%mod,(II+=(i&1?now:mod-now))%=mod;
	II=1ll*II*ksm(3,(1ll*n*n+1)%(mod-1))%mod;
	printf("%d\n",(I+II)%mod);
	return 0;
}