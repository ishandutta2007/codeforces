#include<stdio.h>
int T,n,a,b,c;
int main(){
	scanf("%d",&T);
	while(T--) scanf("%d%d%d",&a,&b,&c),printf("%d %d\n",a>=c?-1:1,a<=c/b?-1:b);
	return 0;
}