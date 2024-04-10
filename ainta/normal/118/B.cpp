#include<stdio.h>
int n,i,j;
int abs(int a){if(a>0)return a;return -a;}
int main(){
	scanf("%d",&n);
	for(i=0;i<2*n+1;i++){
		for(j=0;j<abs(i-n);j++)printf("  ");
		for(j=0;j<n-abs(i-n);j++)printf("%d ",j);
		for(j=0;j<n-abs(i-n);j++)printf("%d ",n-abs(i-n)-j);
		printf("0\n");
	}
}