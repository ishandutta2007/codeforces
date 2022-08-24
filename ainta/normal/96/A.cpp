#include<stdio.h>
#include<string.h>
char p[200],i,n,t;
int main(){
	scanf("%s",p);
	n=strlen(p);
	t=1;
	for(i=1;i<n;i++){
		if(p[i]==p[i-1]) t++;
		else t=1;
		if(t>=7) break;}
	if(i==n) printf("NO");
	else printf("YES");
}