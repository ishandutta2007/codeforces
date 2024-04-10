#include<stdio.h>
int D[2][101][101][12],i,j,k,n,m,o,p,s;
int main(){
	scanf("%d%d%d%d",&n,&m,&o,&p);
	D[0][1][0][1]=1,D[1][0][1][1]=1;
	for(i=2;i<=n+m;i++){
		j=0;
		if(i>m)j=i-m;
		for(j=j;j<=i&&j<=n;j++){
			if(j>=1){
				s=0;
				for(k=1;k<=p;k++) s+=D[1][j-1][i-j][k];
				D[0][j][i-j][1]=s;
				for(k=1;k<o;k++)D[0][j][i-j][k+1]=D[0][j-1][i-j][k];}
			if(i-j>=1){
				s=0;
				for(k=1;k<=o;k++) s+=D[0][j][i-j-1][k];
				D[1][j][i-j][1]=s;
				for(k=1;k<p;k++)D[1][j][i-j][k+1]=D[1][j][i-j-1][k];}
		}
		j=0;
		if(i>m)j=i-m;
		for(j=0;j<=n;j++)for(k=1;k<=o||k<=p;k++)D[0][j][i-j][k]%=100000000,D[1][j][i-j][k]%=100000000;
	}
	s=0;
	for(k=1;k<=o||k<=p;k++)s+=D[0][n][m][k],s+=D[1][n][m][k];
	printf("%d\n",s%100000000);
}