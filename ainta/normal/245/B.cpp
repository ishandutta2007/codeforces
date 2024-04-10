#include<stdio.h>
#include<string.h>
char p[100],r[200],t;
int n,i,c,x,z;
int main(){
	scanf("%s",p);
	n=strlen(p);
	for(i=0;i<n;i++){
		r[c++]=p[i];
		if(p[i]=='p')break;
	}
	z=i;
	r[c++]=':',r[c++]='/',r[c++]='/';
	for(i=z+1;i<n;i++){
		if(i!=z+2&&p[i]=='u'&&t=='r')break;
		t=p[i];
	}
	x=i;
	for(i=z+1;i<x-1;i++)r[c++]=p[i];
	r[c++]='.';for(i=x-1;i<=x;i++)r[c++]=p[i];
	if(x+1!=n){
		r[c++]='/';
		for(i=x+1;i<n;i++)r[c++]=p[i];
	}
	printf("%s\n",r);
}