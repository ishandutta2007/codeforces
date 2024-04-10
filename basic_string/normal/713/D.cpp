#include<bits/stdc++.h>
using namespace std;
const int N=1007;
short lg[N],f[13][13][N][N];
bool a[N][N];
int qry(int x,int y,int z,int w){
	int i=lg[z-x+1],j=lg[w-y+1],p=z-(1<<i)+1,q=w-(1<<j)+1;
	return max(max(f[i][j][x][y],f[i][j][p][q]),max(f[i][j][x][q],f[i][j][p][y]));
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,i,j,k,l,r,t,u,v,w,o;
	cin>>n>>m,lg[0]=-1;
	for(i=1;i<N;++i)lg[i]=lg[i>>1]+1;
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)cin>>a[i][j];
	for(i=n;i;--i)for(j=m;j;--j)if(a[i][j])f[0][0][i][j]=min(min(f[0][0][i][j+1],f[0][0][i+1][j]),f[0][0][i+1][j+1])+1;
	for(i=-1,t=0;i<12;++i,++t)for(j=1,k=(1<<i)+1,l=n-(1<<t)+2;j<l;++j,++k){
		if(t)for(v=1;v<=m;++v)f[t][0][j][v]=max(f[i][0][j][v],f[i][0][k][v]);
		for(u=0;u<12;++u)for(v=1,w=(1<<u)+1,o=m-(1<<u+1)+2;v<o;++v,++w)f[t][u+1][j][v]=max(f[t][u][j][v],f[t][u][j][w]);
	}
	cin>>t;
	while(t--){
		cin>>u>>v>>w>>o,l=1,r=min(w-u,o-v)+1;
		while(l<=r){
			m=l+r>>1;
			if(qry(u,v,w-m+1,o-m+1)<m)r=m-1;
			else l=m+1;
		}
		cout<<l-1<<'\n';
	}
	return 0;
}