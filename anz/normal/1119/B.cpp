#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, h;
int a[1001];
int main()
{
	scanf("%d%d", &n, &h);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	vector<int>p;
	int res = -1;
	for (int i = 0; i < n; i++)
	{
		p.push_back(a[i]);
		sort(p.rbegin(), p.rend());
		
		int result = 0;
		for (int j = 0; j < (i + 1)/2; j++)
		{
			result += p[j * 2];
		}
		if (!(i & 1)) result += p.back();

		if (result > h)
		{
			res = i;
			break;
		}
	}
	if (res == -1) res = n;
	printf("%d", res);
}