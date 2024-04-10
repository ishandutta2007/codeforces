#include<stdio.h>
int w[101][101],n,i,j,R[101];
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&w[i][j]);
		}
		for(j=0;j<n;j++){
			if(i==j)continue;
			R[i]=R[i]|w[i][j];
		}
	}
	for(i=0;i<n;i++)printf("%d ",R[i]);
}