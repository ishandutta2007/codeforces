#include<stdio.h>
int n,w[100001],i,S;
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&w[i]);
		S+=w[i];
	}
	if(S%n==0)printf("%d\n",n);
	else printf("%d\n",n-1);
}