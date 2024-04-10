#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int ksm(int x,int y){
	(y+=(mod-1))%=(mod-1);
	int z=1;
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;
	return z;
}
int n,m,k,s[5010][5010],t[5010],r[5010],res;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	s[0][0]=1;
	for(int i=1;i<=k;i++)for(int j=1;j<=i;j++)s[i][j]=(1ll*s[i-1][j]*j+s[i-1][j-1])%mod;
	t[0]=1;
	for(int i=1;i<=k;i++)t[i]=1ll*t[i-1]*(n-i+1)%mod;
	r[k]=ksm(m,n-k);
	for(int i=k-1;i>=0;i--)r[i]=1ll*r[i+1]*m%mod;
	for(int i=0;i<=k;i++)(res+=1ll*s[k][i]*t[i]%mod*r[i]%mod)%=mod;
	printf("%d\n",1ll*res*ksm(m,-n)%mod);
	return 0;
}