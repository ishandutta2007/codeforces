#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;

int l[101], r[101];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &l[i], &r[i]);
	int k;
	scanf("%d", &k);
	for (int i = 0; i < n; i++)
	{
		if (r[i] > k-1)
		{
			printf("%d", n - i);
			break;
		}	
	}
}