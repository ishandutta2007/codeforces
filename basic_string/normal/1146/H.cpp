#include<bits/stdc++.h>
using namespace std;
enum{N=309};
int x[N],y[N],f[N][N][5];
struct P{int x,y;double t;bool operator<(P a)const{return t<a.t;}}p[N*N];
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,i,j,k,m=0,u,v;
	long long s=0;
	for(cin>>n,i=1;i<=n;++i)cin>>x[i]>>y[i];
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)if(i!=j)p[++m]={i,j,atan2(y[j]-y[i],x[j]-x[i])};
	for(sort(p+1,p+m+1),i=1;i<=m;++i)
	for(f[u=p[i].x][v=p[i].y][0]=j=1;j<=n;++j)for(k=0;k<4;++k)f[j][v][k+1]+=f[j][u][k];
	for(i=1;i<=n;++i)s+=f[i][i][4];
	cout<<s;
	return 0;
}