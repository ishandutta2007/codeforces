#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

const int MAXN = 100007;

int a[MAXN], b[MAXN];

int main()
{
	#ifdef MJUDGE
		assert(freopen("in", "r", stdin));
		assert(freopen("out", "w", stdout));
	#endif
	
	int n;
	
	scanf("%d", &n);
	if (n % 2 == 0)
	{
		puts("-1");
		return 0;
	}
	
	for (int i = 0; i < n; i++)
		a[i] = i;
	
	for (int i = 0; i < n / 2; i++)
		b[i] = n - 2 * i - 1;

	for (int i = 0; i < n / 2; i++)
		b[n - i - 1] = 2 * i + 1;
		
	for (int i = 0; i < n; i++)
	{
		if (i)
			printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");
		
	for (int i = 0; i < n; i++)
	{
		if (i)
			printf(" ");
		printf("%d", b[i]);
	}
	printf("\n");
		
	for (int i = 0; i < n; i++)
	{
		if (i)
			printf(" ");
		printf("%d", (a[i] + b[i]) % n);
	}
	printf("\n");

	fprintf(stderr, "Time execute: %.3lfs\n", clock() / (double)CLOCKS_PER_SEC);
	return 0;
}