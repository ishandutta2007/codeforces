#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>

using namespace std;

int n, b, a;
int s[200001];
int main() {
	scanf("%d%d%d", &n, &b, &a);
	for (int i = 0; i < n; i++)
		scanf("%d", &s[i]);

	int result = 0;
	int cb = b, ca = a;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 0)
		{
			if (ca > 0) ca--;
			else if (cb > 0) cb--;
			else break;
		}
		else
		{
			if (cb > 0)
			{
				if (ca == a && ca > 0) ca--;
				else
					cb--, ca = min(ca + 1, a);
			}
			else if (ca > 0) ca--;
			else break;
		}
		result++;
	}
	printf("%d", result);
}