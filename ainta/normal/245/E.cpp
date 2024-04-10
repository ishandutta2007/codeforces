#include<stdio.h>
#include<string.h>
int S,M,m,n,i;
char p[1000];
int main()
{
	scanf("%s",p);
	n=strlen(p);
	M=m=0;
	for(i=0;i<n;i++){
		if(p[i]=='+')S++;
		else S--;
		if(M<S)M=S;
		if(m>S)m=S;
	}
	printf("%d\n",M-m);
}