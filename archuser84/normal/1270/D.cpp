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

int find(int* arr, int x, int n)
{
	for (int i = 0; i < n; ++i)
		if (arr[i] == x)
			return i;
	return -1;
}

int main()
{
	int n, m, k;
	scanf("%i%i", &n, &k);
	int* q = new int[k + 1];
	int* arr = new int[n + 1]{ 0 };
	for (int i = 0; i <= k; ++i)
		q[i] = i;
	int next = k + 1;
	int a, b;
	for (int i = 0; i < n - k + 1; ++i)
	{
		printf("? ");
		for (int i = 1; i <= k; ++i)
			printf("%i ", q[i]);
		printf("\n");
		fflush(stdout);
		int p, x;
		scanf("%i%i", &p, &x);
		arr[p] = x + 1;
		q[find(q, p, k + 1)] = next++;
		if (i == 0)
			a = p;
		if (i == 1)
			b = p;
	}
	if (arr[a] > arr[b])
	{
		a = a + b;
		b = a - b;
		a = a - b;
	}
	int ans = 0;
	int c = 1;
	for (int i = 0; i < k - 1; ++i)
	{
		while (arr[c] > 0)
			++c;
		printf("? ");
		for (int j = 1; j <= n; ++j)
			if ((arr[j] == 0 && j != c) || j == a || j == b)
				printf("%i ", j);
		printf("\n");
		fflush(stdout);
		int p, x;
		scanf("%i%i", &p, &x);
		ans += p == b;
		++c;
	}
	printf("! %i\n", ans + 1);
	fflush(stdout);
}