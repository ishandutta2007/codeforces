#include<stdio.h>
int n,m,w[100][100],i,j,c;
char p[100][100];
int main(){
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)scanf("%s",p[i]);
	for(i=0;i<n;i++){for(j=0;j<m;j++){if(p[i][j]=='P')w[i+1][j+1]=1;else if(p[i][j]=='W')w[i+1][j+1]=2;}}
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)if(w[i][j]==2&&(w[i-1][j]==1||w[i][j-1]==1||w[i][j+1]==1||w[i+1][j]==1))c++;
	printf("%d\n",c);
}