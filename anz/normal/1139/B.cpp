#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

int n;
long long a[200001];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);

	long long minNum = a[n - 1];
	long long result = a[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		minNum = max(0ll,min(minNum-1, a[i]));
		result += minNum;
	}

	printf("%lld", result);
}