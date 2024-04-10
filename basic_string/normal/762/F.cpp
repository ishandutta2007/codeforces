#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7,N=1013,M=13,O=4101;
int inv(int x){return x<2?1:(P-P/x)*1ll*inv(P%x)%P;}
int n,m,p,g[M][M],f[N][O],s,t;
vector<int>v[N];
void dfs(int x,int y){
	g[x][y]=1<<x-1;
	for(int j:v[x+n])if(j-n!=y)dfs(j-n,x),g[x][y]|=g[j-n][x];
}
void dp(int x,int y){
	int i,k;
	for(i=0;i<m;++i)f[x][1<<i]=1;
	for(int j:v[x])if(j!=y){
		dp(j,x);
		for(k=p-1;~k;--k)for(i=1;i<=m;++i)if(k&(1<<i-1))for(int l:v[i+n])if(!(k&g[l-n][i]))
		f[x][k|g[l-n][i]]=(f[x][k|g[l-n][i]]+f[x][k]*1ll*f[j][g[l-n][i]])%P;
	}
	s=(s+f[x][p-1])%P;
}
int main(){
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<n;++i)scanf("%d%d",&j,&k),v[j].push_back(k),v[k].push_back(j);
	scanf("%d",&m),p=1<<m;
	for(i=1;i<m;++i)scanf("%d%d",&j,&k),v[j+n].push_back(k+n),v[k+n].push_back(j+n);
	for(i=1;i<=m;++i)dfs(i,0);
	dp(1,0),t=s,s=0,dp(n+1,0),printf("%lld",t*1ll*inv(s)%P);
	return 0;
}