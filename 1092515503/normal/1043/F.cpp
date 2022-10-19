#include<bits/stdc++.h>
using namespace std;
const int N=300000;
const int mod[3]={19260817,19491001,17680321};
int ksm(int x,int y,int t){int z=1;for(;y;y>>=1,x=1ll*x*x%mod[t])if(y&1)z=1ll*z*x%mod[t];return z;}
int fac[3][300100],inv[3][300100];
int num[300100],n;
int f[3][300100];
bool che(int x){
	for(int j=0;j<3;j++){
		for(int i=1;i<=N;i++)
			if(num[i]>=x)f[j][i]=1ll*fac[j][num[i]]*inv[j][x]%mod[j]*inv[j][num[i]-x]%mod[j];
			else f[j][i]=0;
		for(int i=N;i;i--)for(int k=2*i;k<=N;k+=i)(f[j][i]+=mod[j]-f[j][k])%=mod[j];
		if(f[j][1])return true;
	}
	return false;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<3;i++){
		fac[i][0]=1;for(int j=1;j<=n;j++)fac[i][j]=1ll*fac[i][j-1]*j%mod[i];
		inv[i][n]=ksm(fac[i][n],mod[i]-2,i);
		for(int j=n;j;j--)inv[i][j-1]=1ll*inv[i][j]*j%mod[i];
	}
	for(int i=1,x;i<=n;i++)scanf("%d",&x),num[x]++;
	for(int i=1;i<=N;i++)for(int j=2*i;j<=N;j+=i)num[i]+=num[j];
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(che(mid))r=mid;
		else l=mid+1;
	}
	if(!che(r))puts("-1");
	else printf("%d\n",r);
	return 0;
}