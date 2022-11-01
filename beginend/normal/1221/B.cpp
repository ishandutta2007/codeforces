#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

int n;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			if ((i+j)&1) putchar('W');
			else putchar('B');
		puts("");
	}
	return 0;
}