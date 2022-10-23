#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n,m,q,x[1000005],y[1000005],z[1000005],ans;
ll f[605][605][2];
void u(ll &x,ll y){
	if(y<x)x=y;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)if(i!=j)f[i][j][0]=f[i][j][1]=f[i][j][2]=orz*100000ll;
	}
	for(int i=1;i<=m;++i){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		x[i]=u,y[i]=v,z[i]=w;
		f[u][v][0]=f[v][u][0]=w;
	}
	scanf("%d",&q);
	for(int i=1;i<=q;++i){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		f[x][y][1]=f[y][x][1]=-z;
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				u(f[i][j][0],f[i][k][0]+f[k][j][0]);
			}
		}
	}
	
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				u(f[i][j][1],f[i][k][0]+f[k][j][1]);
				u(f[i][j][1],f[i][k][1]+f[k][j][0]);
			}
		}
	}
	for(int i=1;i<=m;++i)if(z[i]+f[x[i]][y[i]][1]<=0)++ans;
	printf("%d\n",ans);
    return 0;
}