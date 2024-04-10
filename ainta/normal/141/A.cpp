#include<stdio.h>
#include<string.h>
char a[200],b[200],c[200];
int n,i,D[30],m,k;
int main(){
	scanf("%s",a);
	scanf("%s",b);
	scanf("%s",c);
	n=strlen(a);
	m=strlen(b);
	k=strlen(c);
	for(i=0;i<n;i++)D[a[i]-'A']++;
	for(i=0;i<m;i++)D[b[i]-'A']++;
	for(i=0;i<k;i++)D[c[i]-'A']--;
	for(i=0;i<26;i++)if(D[i]!=0)break;
	if(i==26)printf("YES\n");
	else printf("NO\n");
}