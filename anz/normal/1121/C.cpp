#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <deque>
#include <set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, k;
int a[10001];

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int subNum[101];
	int maxTest[101];
	int testing[101];
	memset(testing, -1, sizeof(testing));
	int curQueue = 0;
	for (int i = 0; i < k; i++)
	{
		if (curQueue >= n) break;
		subNum[i] = curQueue;
		maxTest[i] = a[curQueue++];
		testing[i] = 0;
	}

	int curTime = 0;
	int completed = 0;

	int result = 0;

	bool isInteresting[1001] = { 0, };

	while (completed < n)
	{
		curTime++;
		for (int i = 0; i < k; i++)
		{
			if (testing[i] == -1) continue;
			testing[i]++;

			if (testing[i] > maxTest[i])
			{
				completed++;
				if (curQueue < n)
				{
					subNum[i] = curQueue;
					maxTest[i] = a[curQueue++];
					testing[i] = 1;
				}
				else
				{
					testing[i] = -1;
				}
			}
		}

		int curPercent = (int)(((double)completed * 100) / n + 0.5);

		for (int i = 0; i < k; i++)
		{
			if (testing[i] == curPercent)
				isInteresting[subNum[i]] = true;
		}
	}

	for (int i = 0; i < n; i++)
		if (isInteresting[i]) result++;

	printf("%d", result);
}