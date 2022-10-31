#include<cstdio>
#include<cstring>
using namespace std;
int sum[50][50][50][50]={0},numx[50][50][50][50]={0},numy[50][50][50][50]={0},g[50][50];
int main(){
	int m,n,q,i,j,k,l,a,b,c,d,max,temp;
	scanf("%d %d %d",&m,&n,&q);
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			scanf("%1d",&g[i][j]);
		}
	}
	for(a=1;a<=m;a++){
		for(b=1;b<=n;b++){
			for(j=a;j<=m;j++){
				for(k=b;k<=n;k++){
					sum[a][b][j][k]=sum[a][b][j-1][k]+sum[a][b][j][k-1]-sum[a][b][j-1][k-1];
					max=1000;
					if(g[j][k]){
						numx[a][b][j][k]=0;
						numy[a][b][j][k]=0;
					}
					else{
						numx[a][b][j][k]=numx[a][b][j-1][k]+1;
						numy[a][b][j][k]=numy[a][b][j][k-1]+1;
						for(l=k;l>k-numy[a][b][j][k];l--){
							if(max>numx[a][b][j][l]){
								max=numx[a][b][j][l];
							}
							sum[a][b][j][k]+=max;
						}
					}
				}
			}
		}
	}
	for(i=0;i<q;i++){
		scanf("%d %d %d %d",&a,&b,&c,&d);					
		printf("%d\n",sum[a][b][c][d]);
	}
	return 0;
}