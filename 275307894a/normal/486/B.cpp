#include<cstdio>
using namespace std;
int n,m,k,x,y,z,f[139][139],sum[139][139],c[139][139],d[139][139],a[139][139];
int main(){
	register int i,j,h;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++) scanf("%d",&c[i][j]);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)d[i][j]=1;
	} 
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)if(!c[i][j]){
			for(h=1;h<=n;h++) d[h][j]=0;
			for(h=1;h<=m;h++) d[i][h]=0;
		} 
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++) {
			for(h=1;h<=n;h++) a[i][j]|=d[h][j];
			for(h=1;h<=m;h++) a[i][j]|=d[i][h];
			if(a[i][j]!=c[i][j]){printf("NO\n");return 0;}
		}
	}
	printf("YES\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++) printf("%d ",d[i][j]);
		printf("\n");
	}
}