#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,f[2030][2030],g[2030][2030],res;
int main(){
	scanf("%d%d",&n,&m);
	memset(f,0,sizeof(f)),memset(g,0,sizeof(g));
	for(int i=1;i<=m;i++)f[1][i]=1;
	for(int i=2;i<=n;i++)for(int j=1;j<=m;j++)f[i][j]=(f[i-1][j]+f[i][j-1])%mod;
	for(int i=1;i<n;i++)for(int j=1;j<=m;j++)g[i][j]=(1ll*f[i][m-j+1]*f[i+1][j]+g[i][j-1])%mod;
	for(int i=1;i<n;i++)for(int j=1;j<=m;j++)res=(1ll*f[i][m-j+1]*f[i+1][j]%mod*g[n-i][m-j]+res)%mod;
	
	
	swap(n,m);
	memset(f,0,sizeof(f)),memset(g,0,sizeof(g));
	for(int i=1;i<=m;i++)f[1][i]=1;
	for(int i=2;i<=n;i++)for(int j=1;j<=m;j++)f[i][j]=(f[i-1][j]+f[i][j-1])%mod;
	for(int i=1;i<n;i++)for(int j=1;j<=m;j++)g[i][j]=(1ll*f[i][m-j+1]*f[i+1][j]+g[i][j-1])%mod;
	for(int i=1;i<n;i++)for(int j=1;j<=m;j++)res=(1ll*f[i][m-j+1]*f[i+1][j]%mod*g[n-i][m-j-1]+res)%mod;
	
	printf("%d\n",(res<<1)%mod);
	return 0;
}