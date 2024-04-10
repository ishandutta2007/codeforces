#include<bits/stdc++.h>
using namespace std;
enum{N=209,M=N*N/2};
int u[M],v[M],w[M],d[N][N],rk[N][N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,m,i,j,k,p,ans=2e9;
	for(cin>>n>>m,memset(d,63,sizeof d),i=1;i<=n;++i)d[i][i]=0;
	for(i=1;i<=m;++i)cin>>u[i]>>v[i]>>w[i],d[u[i]][v[i]]=d[v[i]][u[i]]=min(d[u[i]][v[i]],w[i]);
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)for(k=1;k<=n;++k)d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
	for(i=1;i<=n;++i)iota(rk[i],rk[i]+n+1,0),sort(rk[i]+1,rk[i]+n+1,[=](int x,int y){return d[i][x]<d[i][y];});
	for(i=1;i<=n;++i)ans=min(ans,d[i][rk[i][n]]*2);
	for(i=1;i<=m;++i){
		int u=::u[i],v=::v[i],w=::w[i];
		for(j=n-1,p=rk[u][n];j;--j)if(k=rk[u][j],d[v][k]>d[v][p])ans=min(ans,d[u][k]+d[v][p]+w),p=k;
	}
	cout<<ans/2.;
	return 0;
}