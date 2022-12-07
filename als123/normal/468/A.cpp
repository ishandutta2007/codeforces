#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	if (n<4) 	{printf("NO\n");return 0;}
	printf("YES\n");
	if (n%2==0)
	{
		printf("1 * 2 = 2\n");
		printf("2 * 3 = 6\n");
		printf("4 * 6 = 24\n");
		for (int u=5;u<=n;u+=2)
		{
			printf("%d  - %d = 1\n",u+1,u);
			printf("24 * 1 = 24\n");
		}
		return 0;
	}
	else
	{
		printf("4 * 5 = 20\n");
		printf("20 + 3 = 23\n");
		printf("23 + 2 = 25\n");
		printf("25 - 1 = 24\n");
		for (int u=6;u<=n;u+=2)
		{
			printf("%d  - %d = 1\n",u+1,u);
			printf("24 * 1 = 24\n");
		}
		return 0;
	}
	return 0;
}