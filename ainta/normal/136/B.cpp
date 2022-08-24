#include<stdio.h>
int a,b,p[100],q[100],c,d,i,r[100],s;
int main(){
	scanf("%d%d",&a,&b);
	while(a!=0){p[c++]=a%3;a/=3;}
	while(b!=0){q[d++]=b%3;b/=3;}
	for(i=0;i<c||i<d;i++){
		r[i]=(q[i]-p[i]+3)%3;}
	if(d>c)c=d;
	for(i=c-1;i>=0;i--)s*=3,s+=r[i];
	printf("%d\n",s);
}