#include<stdio.h>
int n,i;
int main()
{
	scanf("%d",&n);
	if(n<=2)printf("-1\n");
	else{
		for(i=n;i>=1;i--)printf("%d ",i);
	}
}