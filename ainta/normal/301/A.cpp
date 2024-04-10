#include<stdio.h>
int n,i,w[201],C,M=9999,o,S;
int main()
{
	scanf("%d",&n);
	for(i=0;i<n*2-1;i++){
		scanf("%d",&w[i]);
		if(w[i]<0)C++;
		o=w[i];if(o<0)o=-o;
		if(M>o)M=o;
		S+=o;
	}
	if(n%2==1||C%2==0)printf("%d\n",S);
	else printf("%d\n",S-2*M);
}