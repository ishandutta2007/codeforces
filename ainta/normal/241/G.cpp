#include<stdio.h>
int i,t,s;
int main(){
	printf("302\n");
	printf("0 500000\n");
	s=40000;
	for(i=1;i<=300;i++){
		printf("%d %d\n",s,301-i);
		s+=(301-i)*2;
	}
	printf("1000000 1000000\n");
}