#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,p,f[101][101][101],col[101],cost[101][101],mn=1e18;
signed main(){
	scanf("%lld%lld%lld",&n,&m,&p);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)for(int k=0;k<=p;k++)f[i][j][k]=1e18;
	for(int i=1;i<=n;i++)scanf("%lld",&col[i]);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%lld",&cost[i][j]);
	if(col[1])f[1][col[1]][1]=0;
	else for(int i=1;i<=m;i++)f[1][i][1]=cost[1][i];
	for(int i=2;i<=n;i++)for(int j=1;j<=m;j++)for(int k=1;k<=min(i,p);k++){
		if(col[i]&&j!=col[i])continue;
		for(int l=1;l<=m;l++)f[i][j][k]=min(f[i][j][k],f[i-1][l][k-(j!=l)]+(!col[i])*cost[i][j]);
	}
//	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)for(int k=1;k<=min(i,p);k++)printf("%lld %lld %lld:%lld\n",i,j,k,f[i][j][k]);
	for(int i=1;i<=m;i++)mn=min(mn,f[n][i][p]);
	if(mn==1e18)puts("-1");
	else printf("%lld\n",mn);
	return 0;
}