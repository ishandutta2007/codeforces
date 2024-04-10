#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int n,K,f[101][101][2],d,ans;
int main(){
	scanf("%d%d%d",&n,&K,&d),f[0][0][0]=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int k=1;k<=min(j,K);k++){
		if(k<d)f[i][j][0]+=f[i-1][j-k][0],f[i][j][0]%=MOD,f[i][j][1]+=f[i-1][j-k][1];
		else f[i][j][1]+=(f[i-1][j-k][0]+f[i-1][j-k][1])%MOD;
		f[i][j][1]%=MOD;
	}
	for(int i=1;i<=n;i++)ans+=f[i][n][1],ans%=MOD;
	printf("%d\n",ans);
	return 0;
}