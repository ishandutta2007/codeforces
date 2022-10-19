#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,f[100100][210][2],a[100100],res;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(a[1]==-1)for(int i=1;i<=200;i++)f[1][i][0]=1;
	else f[1][a[1]][0]=1;
	for(int i=1;i<=200;i++)f[1][i][0]+=f[1][i-1][0],f[1][i][1]+=f[1][i-1][1];
	for(int i=2;i<=n;i++){
		if(a[i]!=-1){
			(f[i][a[i]][0]+=(f[i-1][a[i]-1][0]+f[i-1][a[i]-1][1])%mod)%=mod;
			(f[i][a[i]][1]+=(f[i-1][200][1]-f[i-1][a[i]][1]+mod)%mod)%=mod;
			(f[i][a[i]][1]+=((f[i-1][a[i]][0]-f[i-1][a[i]-1][0]+mod)%mod+(f[i-1][a[i]][1]-f[i-1][a[i]-1][1]+mod)%mod)%mod)%=mod;
		}else{
			for(int k=1;k<=200;k++){
				(f[i][k][0]+=(f[i-1][k-1][0]+f[i-1][k-1][1])%mod)%=mod;
				(f[i][k][1]+=(f[i-1][200][1]-f[i-1][k-1][1]+mod)%mod)%=mod;
				(f[i][k][1]+=(f[i-1][k][0]-f[i-1][k-1][0]+mod)%mod)%=mod;
			}
		}
		for(int j=1;j<=200;j++)(f[i][j][0]+=f[i][j-1][0])%=mod,(f[i][j][1]+=f[i][j-1][1])%=mod;
	}
	printf("%d\n",f[n][200][1]);
	return 0;
}