#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
int a, b, c, d;
int main()
{
	scanf("%d%d%d%d", &a, &b, &c, &d);
	if (a > b)
	{
		if (a == b+1 && c+d == 0)
		{
			printf("YES\n");
			for (int i = 0; i < b; i++) printf("0 1 ");
			printf("0\n");
		exit(0);
		}
		else
		{
			printf("NO\n");
			exit(0);
		}
	}
	if (d > c)
	{
		if (d == c+1 && a+b == 0)
		{
			printf("YES\n");
			for (int i = 0; i < c; i++) printf("3 2 ");
			printf("3\n");
		exit(0);
		}
		else
		{
			printf("NO\n");
			exit(0);
		}
	}
	int newb = b-a;
	int newc = c-d;
	if (abs(newb-newc) > 1) 
	{
		printf("NO\n");
		exit(0);
	}
	if (newb == newc)
	{
		printf("YES\n");
		for (int i = 0; i < a; i++) printf("0 1 ");
		for (int i = 0; i < newb; i++) printf("2 1 ");
		for (int i = 0; i < d; i++) printf("2 3 ");
		printf("\n");
		exit(0);
	}
	if (newb + 1 == newc)
	{
		printf("YES\n");
		for (int i = 0; i < a; i++) printf("0 1 ");
		for (int i = 0; i < newb; i++) printf("2 1 ");
		for (int i = 0; i < d; i++) printf("2 3 ");
		printf("2\n");
		exit(0);
	}
	else
	{
		printf("YES\n");
		printf("1 ");
		for (int i = 0; i < a; i++) printf("0 1 ");
		for (int i = 0; i < newc; i++) printf(" 2 1 ");
		for (int i = 0; i < d; i++) printf("2 3 ");
		printf("\n");
		exit(0);
	}
}