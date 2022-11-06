#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int n;
long long stick[300001];
queue <int> v;

int main()
{
	long long result = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &stick[i]);
		if (stick[i] >= 2) v.push(i);
	}
	for (int i = 0; i < n; i++)
	{
		if (stick[i] == 0) continue;
		if (stick[i] >= 2) v.pop();
		result += stick[i] / 3;
		stick[i] %= 3;
		while (stick[i] > 0 && !v.empty())
		{
			stick[v.front()] -= 2;
			stick[i]--;
			if (stick[v.front()] < 2) v.pop();
			result++;
		}

	}
	printf("%lld", result);
}