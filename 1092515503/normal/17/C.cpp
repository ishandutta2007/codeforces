#include<bits/stdc++.h>
using namespace std;
const int mod=51123987;
int n,f[160][52][52][52],nex[160][3],lim,res,C[160][160];
char s[160];
int c(int x,int y){
	if(y==-1)return x==-1;
	if(x==-1)return 0;
	return C[x][y];
}
int coeff(int i,int j,int k){
	int N=n/3;
	i--,j--,k--;
	if(n%3==0)return 1ll*c(N-1,i)*c(N-1,j)%mod*c(N-1,k)%mod;
	if(n%3==1)return(1ll*c(N-1,i)*c(N-1,j)%mod*c(N,k)%mod+1ll*c(N-1,i)*c(N,j)%mod*c(N-1,k)%mod+1ll*c(N,i)*c(N-1,j)%mod*c(N-1,k)%mod)%mod;
	if(n%3==2)return(1ll*c(N,i)*c(N,j)%mod*c(N-1,k)%mod+1ll*c(N,i)*c(N-1,j)%mod*c(N,k)%mod+1ll*c(N-1,i)*c(N,j)%mod*c(N,k)%mod)%mod;
} 
int main(){
	scanf("%d",&n),lim=(n-1)/3+1;
	for(int i=0;i<=n;i++)C[i][0]=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	scanf("%s",s+1);
	for(int j=0;j<3;j++)nex[n][j]=n+1;
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<3;j++)nex[i][j]=nex[i+1][j];
		nex[i][s[i+1]-'a']=i+1;
	}
	for(int j=0;j<3;j++)f[nex[0][j]][0][0][0]=1;
	for(int i=1;i<=n;i++)for(int j=0;j<=lim;j++)for(int k=0;k<=lim;k++)for(int l=0;l<=lim;l++){
		if(!f[i][j][k][l])continue;
		for(int p=0;p<3;p++){
			if(p==s[i]-'a')continue;
			if(nex[i][p]==n+1)continue;
			if(s[i]-'a'==0)(f[nex[i][p]][j+1][k][l]+=f[i][j][k][l])%=mod;
			if(s[i]-'a'==1)(f[nex[i][p]][j][k+1][l]+=f[i][j][k][l])%=mod;
			if(s[i]-'a'==2)(f[nex[i][p]][j][k][l+1]+=f[i][j][k][l])%=mod;
		}	
		if(s[i]-'a'==0)(f[n+1][j+1][k][l]+=f[i][j][k][l])%=mod;
		if(s[i]-'a'==1)(f[n+1][j][k+1][l]+=f[i][j][k][l])%=mod;
		if(s[i]-'a'==2)(f[n+1][j][k][l+1]+=f[i][j][k][l])%=mod;
	}
	for(int i=0;i<=lim;i++)for(int j=0;j<=lim;j++)for(int k=0;k<=lim;k++)(res+=1ll*f[n+1][i][j][k]*coeff(i,j,k)%mod)%=mod;
	printf("%d\n",res);
	return 0;
}