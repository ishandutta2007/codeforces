#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 666;
const LL inf = 1e18;
void cmin(LL&x,LL y){
	if(x>y)
		x=y;
}
void cmax(LL&x,LL y){
	if(x<y)
		x=y;
}
int n,m,q,ans;
LL d[N][N],e[N][N],f[N][N],g[N];
int main(){
	int i,j,k,l,x,y,z;
	LL o;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i!=j)
				d[i][j]=inf,e[i][j]=inf;
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		cmin(e[x][y],z);
		cmin(e[y][x],z);
		cmin(d[x][y],z);
		cmin(d[y][x],z);
	}
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				cmin(d[i][j],d[i][k]+d[k][j]);
	scanf("%d",&q);
	for(i=1;i<=q;i++){
		scanf("%d%d%d",&x,&y,&z);
		cmax(f[x][y],z);
		cmax(f[y][x],z);
	}
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++)
			g[i]=-inf;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				cmax(g[j],f[i][j]-d[i][k]);
		for(l=k+1;l<=n;l++){
			o=0;
			for(j=1;j<=n;j++)
				cmax(o,g[j]-d[l][j]);
			//cout<<k<<l<<' '<<o<<endl;
			if(o>=e[k][l])
				ans++;
		}
	}
	cout<<ans;
	return 0;
}