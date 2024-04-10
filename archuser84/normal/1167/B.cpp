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
	const int nums[6] = { 4 , 8, 15, 16, 23, 42 };
	bool u[100] = { 0 };
	int a[6];
	
	printf("? 1 1\n");
	fflush(stdout);
	scanf("%i", &a[0]);
	a[0] = sqrt(a[0]);
	u[a[0]] = true;
	
	printf("? 2 2\n");
	fflush(stdout);
	scanf("%i", &a[1]);
	a[1] = sqrt(a[1]);
	u[a[1]] = true;

	int x, y;
	printf("? 3 4\n");
	fflush(stdout);
	scanf("%i", &x);
	printf("? 3 5\n");
	fflush(stdout);
	scanf("%i", &y);

	if (x % 5 == 0 && y % 5 == 0)
		a[2] = 15;
	else if (x % 23 == 0 && y % 23 == 0)
		a[2] = 23;
	else if (x % 7 == 0 && y % 7 == 0)
		a[2] = 42;
	else
	{
		if (x % 5 == 0)
			a[2] = x/15;
		else if (x % 23 == 0)
			a[2] = x/23;
		else if (x % 7 == 0 )
			a[2] = x/42;
		else if (y % 5 == 0)
			a[2] = y / 15;
		else if (y % 23 == 0)
			a[2] = y / 23;
		else if (y % 7 == 0)
			a[2] = y / 42;
		else
		{
			if (x + y == 16 * 12)
				a[2] = 16;
			else if (x + y == 8 * 20)
				a[2] = 8;
			else if (x + y == 4 * 24)
				a[2] = 4;
		}
	}
	u[a[2]] = true;

	a[3] = x / a[2];
	a[4] = y / a[2];
	u[a[3]] = true;
	u[a[4]] = true;

	for (int i : nums)
		if (!u[i])
		{
			a[5] = i;
			break;
		}

	printf("!");
	for (int i = 0; i < 6; ++i)
		printf(" %i", a[i]);
	printf("\n");
	fflush(stdout);
}