#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}

int n;
bool hand[200001];
int deck[200001];
int deck_o[200001];

int main()
{
	int t;
	memset(deck, -1, sizeof deck);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		hand[t] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		deck_o[i] = t;
		deck[t] = i;
	}

	int dist1 = deck[1];
	if (dist1 == -1)
	{
		bool flag = true;
		for (int i = 2; i <= n; i++)
		{
			if (!hand[i] && deck[i] > i - 2)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			printf("%d", n);
			return 0;
		}
	}
	else
	{
		int cnt = 1;
		bool flag = true;
		while (true)
		{
			int next = deck[1] + cnt;
			if (next >= n) break;
			cnt++;
			if (deck[cnt] != next)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			if (cnt >= n)
			{
				printf("0");
				return 0;
			}

			cnt++;
			if (!hand[cnt]) flag = false;
			else
			{
				int idx = 0;
				while (cnt + 1 + idx <= n)
				{
					if (deck[cnt + 1 + idx] > idx)
					{
						flag = false;
						break;
					}
					idx++;
				}
			}
		}

		if (flag)
		{
			printf("%d", deck[1]);
			return 0;
		}
	}

	int res = dist1;
	for (int i = dist1 + 1; i < n; i++)
	{
		if (deck_o[i] == 0) continue;
		if (i - deck_o[i] + 1 > res) res = i - deck_o[i] + 1;
	}
	printf("%d", res + 1 + n);
}