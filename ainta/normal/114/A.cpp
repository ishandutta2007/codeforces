#include<stdio.h>
int n,k,s;
int main(){
	scanf("%d%d",&k,&n);
	while(n>k&&n%k==0){s++;n/=k;}
	if(n!=k)printf("NO\n");
	else printf("YES\n%d\n",s);
}