#include<cstdio>
int main()
{
	int a, b;
	scanf("%d%d",&a,&b);
	if(a>b)
	printf("%d %d\n",b, (a-b)/2);
	else printf("%d %d\n",a,(b-a)/2);
	return 0;
}