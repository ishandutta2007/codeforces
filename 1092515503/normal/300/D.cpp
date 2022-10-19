#include<bits/stdc++.h>
using namespace std;
int cnt,n,K,T,f[100][10000],g[100][10000];
const int mod=7340033;
void init(){
	for(int i=0;i<=30;i++)f[i][0]=g[i][0]=1;//for squares of any size, if we do not have any cuts, there will only be one situation
	for(int i=1;i<=30;i++)for(int j=1;j<=1000;j++){
		for(int k=0;k<j;k++)f[i][j]=(1ll*g[i-1][k]*g[i-1][j-k-1]%mod+f[i][j])%mod;
		for(int k=0;k<=j;k++)g[i][j]=(1ll*f[i][k]*f[i][j-k]%mod+g[i][j])%mod;
	}
}
int main(){
	init();
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&K),cnt=0;
		for(;(n&1)&&(n>1);n>>=1)cnt++;
		printf("%d\n",f[cnt][K]);
	}
	return 0;
}