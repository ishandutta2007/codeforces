#include<stdio.h>
int main(){
	int a,b,c,d,e,f;
	int w,x,y,z;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	if(a+b!=c+d||c+d!=e+f||e+f!=a+b){printf("-1\n");return 0;}
	w=(c+e-b)/2;
	x=a-w;
	y=c-w;
	z=d-x;
	if(w+x!=a||y+z!=b||w+y!=c||x+z!=d||w+z!=e||x+y!=f){printf("-1\n");return 0;}
	if(w<1||w>9||x<1||x>9||y<1||y>9||z<1||z>9||w==x||w==y||w==z||x==y||x==z||y==z){printf("-1\n");return 0;}
	printf("%d %d\n%d %d\n",w,x,y,z);
}