#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int n;
	int door[200001];
	int left = 0, right = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &door[i]);
		if (door[i] == 0) left++;
		else right++;
	}
	
	int cleft = 0, cright = 0;
	for (int i = 0; i < n; i++)
	{
		if (door[i] == 0) cleft++;
		else cright++;

		if (cleft == left || cright == right)
		{
			printf("%d", i + 1);
			return 0;
		}
	}

}