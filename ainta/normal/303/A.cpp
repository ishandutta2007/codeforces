#include<stdio.h>
int main()
{
	int n,i;
	scanf("%d",&n);
	if(n%2==0){
		printf("-1\n");
	}
	else{
		for(i=0;i<n;i++){
			printf("%d ",i);
		}
		printf("\n");
		for(i=0;i<n;i++){
			printf("%d ",i);
		}
		printf("\n");
		for(i=0;i<n;i++){
			printf("%d ",(i*2)%n);
		}
	}
}