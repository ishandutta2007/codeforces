#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int c[300001];
int main()
{
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);

	int result = 1;
	if (c[0] != c[n - 1])
		result = n - 1;
	else
		for (int i = 1; i < n - 1; i++)
		{
			if (c[0] != c[i])
				result = max(result, i);
			if (c[n - 1] != c[i])
				result = max(result, n - 1 - i);
		}

	printf("%d", result);
}