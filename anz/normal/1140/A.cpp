#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int maxNum = 0;
	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		int t;
		scanf("%d", &t);
		maxNum = max(maxNum, t);
		if (i >= maxNum)
		{
			result++;
			maxNum = 0;
		}
	}
	printf("%d", result);
}