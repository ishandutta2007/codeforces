#include<bits/stdc++.h>
using namespace std;
const int MOD=1e8;
int f[201][101][2][11],n1,n2,k1,k2,ans;
int main(){
	scanf("%d%d%d%d",&n1,&n2,&k1,&k2),f[1][1][0][1]=f[1][0][1][1]=1;
	for(int i=2;i<=n1+n2;i++)for(int j=0;j<=min(i,n1);j++){
		f[i][j][0][1]=f[i-1][j-1][1][1],f[i][j][1][1]=f[i-1][j][0][1];
		for(int k=2;k<=min(j,k1);k++)f[i][j][0][k]=f[i-1][j-1][0][k-1],f[i][j][1][1]+=f[i-1][j][0][k],f[i][j][1][1]%=MOD;
		for(int k=2;k<=min(i-j,k2);k++)f[i][j][1][k]=f[i-1][j][1][k-1],f[i][j][0][1]+=f[i-1][j-1][1][k],f[i][j][0][1]%=MOD;
	}
	for(int i=1;i<=k1;i++)ans+=f[n1+n2][n1][0][i],ans%=MOD;
	for(int i=1;i<=k2;i++)ans+=f[n1+n2][n1][1][i],ans%=MOD;
	printf("%d\n",ans);
	return 0;
}