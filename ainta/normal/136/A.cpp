#include<stdio.h>
int n,w[101],i,j;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&w[i]);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(w[j]==i){
				printf("%d ",j);
				break;
			}
		}
	}
}