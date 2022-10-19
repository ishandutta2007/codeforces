#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,p,a[100],f[100][2][2][2],bin[100],res;
//f[i][j][k][l]:the number of situations where there're odd/even roads which ends in i, there has(not) an odd black, has(not) an odd white
int main(){
	scanf("%d%d",&n,&p),bin[0]=1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),bin[i]=(bin[i-1]<<1)%mod;
	f[0][0][0][0]=1;
	for(int i=0;i<n;i++)for(int j=0;j<2;j++)for(int k=0;k<2;k++)for(int l=0;l<2;l++){
		if(!f[i][j][k][l])continue;
		int tmp=f[i][j][k][l];
		if(a[i+1]!=0){//can be white
			if(k)(f[i+1][j][k][l]+=1ll*tmp*bin[i-1]%mod)%=mod,(f[i+1][j^1][k][true]+=1ll*tmp*bin[i-1]%mod)%=mod;
			else (f[i+1][j^1][k][true]+=1ll*tmp*bin[i]%mod)%=mod;
		}
		if(a[i+1]!=1){//can be black
			if(l)(f[i+1][j][k][l]+=1ll*tmp*bin[i-1]%mod)%=mod,(f[i+1][j^1][true][l]+=1ll*tmp*bin[i-1]%mod)%=mod;
			else (f[i+1][j^1][true][l]+=1ll*tmp*bin[i]%mod)%=mod;
		}
	}
	for(int k=0;k<2;k++)for(int l=0;l<2;l++)(res+=f[n][p][k][l])%=mod;
	printf("%d\n",res);
	return 0;
}