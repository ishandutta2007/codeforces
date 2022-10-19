#include<bits/stdc++.h>
using namespace std;
const int lim=1<<20;
const int mod=1e9+7;
int f[lim],n,pov[1001000];
int main(){
	scanf("%d",&n),pov[0]=1;
	for(int i=1,x;i<=n;i++)scanf("%d",&x),f[x]++,pov[i]=(pov[i-1]<<1)%mod;
	for(int j=0;j<20;j++)for(int i=lim-1;i>=0;i--)if(!(i&(1<<j)))(f[i]+=f[i|(1<<j)])%=mod;
	for(int i=0;i<lim;i++)f[i]=pov[f[i]]-1;
	for(int j=0;j<20;j++)for(int i=lim-1;i>=0;i--)if(!(i&(1<<j)))(f[i]=f[i]+mod-f[i|(1<<j)])%=mod;
	printf("%d\n",f[0]);
	return 0;
}