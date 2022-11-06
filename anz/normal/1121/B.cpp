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

int n;
int a[100001];
int hasNum[100001] = { 0, };
int cache[100001];
set <int> candy;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		hasNum[a[i]] = i;
	}



	int result = 0;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			candy.insert(a[i] + a[j]);
		}
	}

	set<int>::iterator i;
	for (i = candy.begin(); i != candy.end(); i++)
	{
		memset(cache, -1, sizeof(cache));
		int candy = (*i);
		int curSum = 0;

		for (int k = 0; k < n; k++)
		{
			int firstCandy = a[k];
			if (cache[k] != -1) continue;

			int secondCandy = candy - firstCandy;
			if (firstCandy == secondCandy) continue;
			if (1 <= secondCandy && secondCandy <= 100000
				&& hasNum[secondCandy] && cache[hasNum[secondCandy]] == -1)
			{
				cache[k] = cache[hasNum[secondCandy]] = 1;
				curSum++;
			}
		}

		result = max(result, curSum);
	}

	printf("%d", result);

}