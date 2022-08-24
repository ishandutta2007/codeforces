#include<stdio.h>
#include<string.h>
char p[100010];
int n,i,c;
int main(){
	scanf("%s",p);
	n=strlen(p);
	for(i=0;i<n;i++)if(p[i]=='0')break;
	c=i;
	if(c==n)c=n-1;
	for(i=0;i<c;i++)printf("%c",p[i]);
	for(i=c+1;i<n;i++)printf("%c",p[i]);
	printf("\n");
}