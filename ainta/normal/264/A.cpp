#include<stdio.h>
#include<string.h>
int p1,p2,n,w[1000001],i;
char p[1000001];
int main(){
	scanf("%s",p);
	n=strlen(p);
	p1=1,p2=n;
	for(i=0;i<n;i++){
		if(p[i]=='l')w[p2--]=i+1;
		else w[p1++]=i+1;
	}
	for(i=1;i<=n;i++)printf("%d\n",w[i]);
}