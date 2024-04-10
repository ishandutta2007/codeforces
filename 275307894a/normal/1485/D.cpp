#include<cstdio>
using namespace std;
int n,m,k,x,y,z,a[539][539],b[530][539];
int main(){
	register int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++) scanf("%d",&a[i][j]);
	}
	for(i=1;i<=n;i++){
		for(j=(i&1)+1;j<=m;j+=2) b[i][j]=a[i][j]*a[i][j]*a[i][j]*a[i][j];
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++) printf("%d ",b[i][j]+720720);printf("\n");
	}
}