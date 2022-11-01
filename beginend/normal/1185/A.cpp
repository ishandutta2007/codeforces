#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if (a>b) std::swap(a,b);
	if (a>c) std::swap(a,c);
	if (b>c) std::swap(b,c);
	printf("%d\n",std::max(0,d-(b-a))+std::max(0,d-(c-b)));
	return 0;
}