#include<stdio.h>
#include<string.h>
char p[200];
int n,i;
int main(){
	scanf("%s",p);
	n=strlen(p);
	for(i=0;i<n;i++){
		if(p[i]<'a') p[i]+='a'-'A';
		if(p[i]=='a'||p[i]=='e'||p[i]=='i'||p[i]=='o'||p[i]=='u'||p[i]=='y')continue;
		printf(".%c",p[i]);
	}
}