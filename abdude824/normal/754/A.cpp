#include<stdio.h>
#include<stdlib.h>
typedef unsigned u;
u A[111];
int main()
{
	u n,i=-1,j=0;
	for(scanf("%u",&n);++i<n;j+=A[i])scanf("%u",A+i);
	if(j){printf("YES\n1\n1 %u\n",n);return 0;}
	for(i=-1;++i<n&&!A[i];);
	printf(i!=n?"YES\n2\n1 %u\n%u %u\n":"NO\n",i+1,i+2,n);
	return 0;
}