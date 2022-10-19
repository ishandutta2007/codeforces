#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,f[510][510][2];
bool g[510][510];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&g[i][j]);
	for(int i=1;i<=n;i++)f[i][i][0]=1;
	for(int l=2;l<=n;l++)for(int i=1,j=i+l-1;j<=n;i++,j++){
		if(g[i][j])for(int k=i;k<j;k++)(f[i][j][0]+=1ll*(f[i][k][0]+f[i][k][1])*(f[k+1][j][0]+f[k+1][j][1])%mod)%=mod;
		for(int k=i+1;k<j;k++)if(g[i][k])(f[i][j][1]+=1ll*f[i][k][0]*(f[k][j][0]+f[k][j][1])%mod)%=mod;
	}
	printf("%d\n",(f[1][n][0]+f[1][n][1])%mod);
	return 0;
}