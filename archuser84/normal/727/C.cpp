#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop int loop = 0; loop < t; ++loop
#define LoopN int i = 0; i < n; ++i
#define LoopM int j = 0; j < m; ++j
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int main()
{
	int n;
	int x[10000];
	scanf("%i", &n);
	int a, b, c;
	printf("? 1 2\n");
	fflush(stdout);
	scanf("%i", &a);
	printf("? 2 3\n");
	fflush(stdout);
	scanf("%i", &b);
	printf("? 3 1\n");
	fflush(stdout);
	scanf("%i", &c);
	x[0] = (a - b + c) / 2;
	x[1] = (b - c + a) / 2;
	x[2] = (c - a + b) / 2;
	for (int i = 3; i < n; ++i)
	{
		printf("? %i %i\n", i, i + 1);
		fflush(stdout);
		scanf("%i", &x[i]);
		x[i] -= x[i - 1];
	}
	printf("!");
	for (LoopN)
		printf(" %i", x[i]);
	printf("\n");
	fflush(stdout);
}