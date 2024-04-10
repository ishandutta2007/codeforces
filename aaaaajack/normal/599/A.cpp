#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int a,b,c,x1,x2,x3,x4;
	scanf("%d%d%d",&a,&b,&c);
	x1=a+b+c;
	x2=a+b+a+b;
	x3=a+c+a+c;
	x4=b+c+b+c;
	if(x2<x1) x1=x2;
	if(x3<x1) x1=x3;
	if(x4<x1) x1=x4;
	printf("%d\n",x1);
	return 0;
}