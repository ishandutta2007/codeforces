#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m,f[2010][2010],res,g[2010][2010];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=2;i<=m;i++)f[1][i]=1;
	for(int i=2;i<=n;i++)for(int j=2;j<=m;j++)(f[i][j]=(0ll+f[i-1][j]+f[i][j-1]*2-f[i][j-2]+mod)%mod);
	for(int i=1;i<=n;i++)for(int j=2;j<=m;j++)g[i][j]=(g[i-1][j]+f[i][j])%mod;
	for(int i=1;i<=n;i++)for(int j=2;j<=m;j++)(res+=1ll*f[i][j]*g[n+1-i][j]%mod*(m-j+1)%mod)%=mod;
	printf("%d\n",res);
	return 0;
}