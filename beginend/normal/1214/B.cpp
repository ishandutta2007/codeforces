#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

int b,g,n;

int main()
{
	scanf("%d%d%d",&b,&g,&n);
	if (n<=std::min(b,g)) printf("%d\n",n+1);
	else
	{
		int l1=std::max(0,n-g),r1=std::min(b,n);
		int l2=std::max(0,n-b),r2=std::min(g,n);
		printf("%d\n",r1-l1+1);
	}
	return 0;
}