#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int a,b,c,d,e;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	c/=2;
	d/=7;
	e/=4;
	a=min(a,min(b,min(c,min(d,e))));
	printf("%d\n",a);
	return 0;
}