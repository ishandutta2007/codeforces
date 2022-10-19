#include<bits/stdc++.h>
using namespace std;
int n,mod,com[510],f[125100],fac[510],s[125100],t[125100],C[510][510],d[510],res;
int main(){
	scanf("%d%d",&n,&mod);
	for(int i=1;i<=n;i++)com[i]=i*(i-1)/2;
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=0;i<=n;i++)C[i][0]=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	f[0]=1;
	for(int i=0;i<n;i++){
		for(int j=1;j<=com[i];j++)(f[j]+=f[j-1])%=mod;f[com[i]+1]=0;
//		for(int j=0;j<=com[i];j++)printf("%d ",f[j]);puts("");
		for(int j=0;j<=i;j++)d[j]=0;
		for(int J=0;J<=i;J++)for(int K=J+1;K<=i;K++)d[K-J]++;
		for(int j=1;j<=i;j++)d[j]+=d[j-1];
//		for(int j=0;j<=i;j++)printf("%d ",d[j]);puts("");
		for(int j=0;j<=com[i];j++)s[j]=f[j],t[j]=1ll*f[j]*j%mod;
		for(int j=1;j<=com[i];j++)(s[j]+=s[j-1])%=mod,(t[j]+=t[j-1])%=mod;
		for(int j=2,k=0;j<=com[i];j++){
			if(j>i)(res+=1ll*d[i]*fac[n-i-1]%mod*C[n][n-i-1]%mod*f[j]%mod*s[j-i-1]%mod)%=mod,(k+=mod-1ll*f[j-i-1]*d[i]%mod)%=mod;
			(k+=(0ll+t[j-2]+mod-1ll*(j-i-2)*s[j-2]%mod)%mod)%=mod;
			if(j-1>i)(k+=(2ll*mod-t[j-i-2]+1ll*(j-i-2)*s[j-i-2]%mod)%mod)%=mod;
			(res+=1ll*C[n][n-i-1]*fac[n-i-1]%mod*f[j]%mod*k%mod)%=mod;
		}
		for(int j=com[i];j>=0;j--)(f[j+i+1]+=mod-f[j])%=mod;
//		puts("");
	}
	printf("%d\n",res);
	return 0;
}
/*
4 403458372
*/