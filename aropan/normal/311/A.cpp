#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	int n, k;
	scanf("%d %d", &n, &k);
	if (n * (n - 1) / 2 <= k)
	{
		puts("no solution");
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		printf("0 %d\n", i);
	}
	return 0;	
}