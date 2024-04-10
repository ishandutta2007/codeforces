#include<stdio.h>
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	if(a==1){printf("%d\n",b);return 0;}
	if(b==1){printf("%d\n",a);return 0;}
	if(a==2){if(b%4==0)printf("%d\n",a*b/2);else if(b%4!=3) printf("%d\n",a*b/2+b%4);else printf("%d\n",a*b/2+1);return 0;}
	if(b==2){if(a%4==0)printf("%d\n",a*b/2);else if(a%4!=3) printf("%d\n",a*b/2+a%4);else printf("%d\n",a*b/2+1);return 0;}
	printf("%d\n",(a*b+1)/2);
}