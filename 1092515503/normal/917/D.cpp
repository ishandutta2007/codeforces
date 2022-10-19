#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,f[110][110][110],g[110],sz[110],h[110][110],fac[110],inv[110];
vector<int>v[110];
int ksm(int x,int y=mod-2){
	int z=1;
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;
	return z;
}
void dfs(int x,int fa){
	sz[x]=1,f[x][1][1]=1;
	for(auto y:v[x]){
		if(y==fa)continue;
		dfs(y,x);
		for(int i=1;i<=sz[x];i++)for(int I=1;I<=sz[y];I++)for(int j=1;j<=sz[x];j++)for(int J=1;J<=sz[y];J++){
			(h[i+I][j]+=1ll*f[x][i][j]*f[y][I][J]%mod*J%mod)%=mod;
			(h[i+I-1][j+J]+=1ll*f[x][i][j]*f[y][I][J]%mod)%=mod;
		}
		for(int i=1;i<=sz[x]+sz[y];i++)for(int j=1;j<=sz[x]+sz[y];j++)f[x][i][j]=h[i][j],h[i][j]=0;
		sz[x]+=sz[y];
	}
}
int C(int x,int y){return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=ksm(fac[n]);for(int i=n-1;i>=0;i--)inv[i]=1ll*inv[i+1]*(i+1)%mod;
	dfs(1,0);
	for(int i=0,k=ksm(n);i<n;i++,k=1ll*k*n%mod){
		for(int j=1;j<=n;j++)(g[i]+=1ll*f[1][i+1][j]*j%mod)%=mod;
		g[i]=1ll*g[i]*k%mod;
	}
	for(int i=0;i<n;i++)for(int j=0;j<i;j++)(g[i]+=mod-1ll*g[j]*C(n-j-1,i-j)%mod)%=mod;
	for(int i=0;i<n;i++)printf("%d ",g[n-i-1]);
	return 0;
}