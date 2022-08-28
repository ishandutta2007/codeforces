#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 555;
const int K = 15;
const int inf = 1e9;
void cmin(int&x,int y){
	if(x>y)
		x=y;
}
int n,m,k,a[N][N],b[N][N],f[N][N][K];
int main(){
	int i,j,o;
	scanf("%d%d%d",&n,&m,&k);
	if(k%2){
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++)
				printf("-1 ");
			printf("\n");
		}
		return 0;
	}
	k/=2;
	for(i=1;i<=n;i++)
		for(j=1;j<m;j++)
			scanf("%d",a[i]+j);
	for(i=1;i<n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",b[i]+j);
	for(o=1;o<=k;o++){
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				f[i][j][o]=inf;
				if(i>1)
					cmin(f[i][j][o],f[i-1][j][o-1]+b[i-1][j]);
				if(i<n)
					cmin(f[i][j][o],f[i+1][j][o-1]+b[i][j]);
				if(j>1)
					cmin(f[i][j][o],f[i][j-1][o-1]+a[i][j-1]);
				if(j<m)
					cmin(f[i][j][o],f[i][j+1][o-1]+a[i][j]);
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)
			printf("%d ",f[i][j][k]*2);
		printf("\n");
	}
	return 0;
}