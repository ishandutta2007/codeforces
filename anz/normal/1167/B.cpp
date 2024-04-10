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
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <climits>
#include <cmath>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}

int arr[6] = { 4,8,15,16,23,42 };
int res[6];
int main()
{
	int ans[4];
	printf("? 1 2\n");
	fflush(stdout);
	scanf("%d", &ans[0]);
	printf("? 2 3\n");
	fflush(stdout);
	scanf("%d", &ans[1]);
	printf("? 3 4\n");
	fflush(stdout);
	scanf("%d", &ans[2]);
	printf("? 4 5\n");
	fflush(stdout);
	scanf("%d", &ans[3]);

	for (int i = 0; i < 6; i++) for (int j = i + 1; j < 6; j++)
	{
		if (arr[i] * arr[j] == ans[0])
		{
			res[0] = arr[i];
			res[1] = arr[j];
		}
	}

	for (int i = 0; i < 6; i++) for (int j = i + 1; j < 6; j++)
	{
		if (arr[i] * arr[j] == ans[1])
		{
			if (res[1] == arr[i])
			{
				res[2] = arr[j];
			}
			else if (res[1] == arr[j])
			{
				res[2] = arr[i];
			}
			else
			{
				swap(res[0], res[1]);
				if (res[1] == arr[i])
				{
					res[2] = arr[j];
				}
				else
				{
					res[2] = arr[i];
				}
			}
		}
	}

	for (int i = 0; i < 6; i++) for (int j = i + 1; j < 6; j++)
	{
		if (arr[i] * arr[j] == ans[2])
		{
			if (res[2] == arr[i])
			{
				res[3] = arr[j];
			}
			else if (res[2] == arr[j])
			{
				res[3] = arr[i];
			}
		}
	}

	for (int i = 0; i < 6; i++) for (int j = i + 1; j < 6; j++)
	{
		if (arr[i] * arr[j] == ans[3])
		{
			if (res[3] == arr[i])
			{
				res[4] = arr[j];
			}
			else if (res[3] == arr[j])
			{
				res[4] = arr[i];
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < 6; i++) sum += arr[i];
	for (int i = 0; i < 5; i++) sum -= res[i];

	res[5] = sum;

	printf("! %d %d %d %d %d %d", res[0], res[1], res[2], res[3], res[4], res[5]);
}