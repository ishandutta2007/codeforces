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

int n;
vector <pii> arr;
map <int, int> dif;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int t;
		scanf("%d", &t);
		arr.push_back({ t,i + 1 });
	}
	sort(arr.begin(), arr.end());

	for (int i = 1; i < n; i++)
	{
		int d = arr[i].first - arr[i - 1].first;
		if (dif.count(d) == 0)
			dif[d] = 1;
		else
			dif[d]++;
	}

	if (dif.size() > 3) printf("-1");
	else if (dif.size() == 3)
	{
		auto i = dif.begin();
		pii a = *i; i++;
		pii b = *i; i++;
		pii c = *i; i++;

		if (a.second == 1 && b.second == 1 && a.first + b.first == c.first)
		{
			bool flag = false;
			for (int i = 2; i < n; i++)
			{
				if (arr[i].first - arr[i - 1].first == a.first && arr[i - 1].first - arr[i - 2].first == b.first ||
					arr[i].first - arr[i - 1].first == b.first && arr[i - 1].first - arr[i - 2].first == a.first)
				{
					flag = true;
					printf("%d", arr[i - 1].second);
					break;
				}
			}

			if (!flag) printf("-1");
		}

		else
			printf("-1");

	}
	else if (dif.size() == 2)
	{
		auto i = dif.begin();
		pii a = *i; i++;
		pii b = *i; i++;

		if (a.second == 1)
		{
			if (arr[1].first - arr[0].first == a.first)
				printf("%d", arr[0].second);
			else if (arr[n - 1].first - arr[n - 2].first == a.first)
				printf("%d", arr[n - 1].second);
			else if (a.first == 0)
			{
				for (int i = 1; i < n; i++)
				{
					int d = arr[i].first - arr[i - 1].first;
					if (d == 0)
					{
						printf("%d", arr[i].second);
						break;
					}
				}
			}
			else
				printf("-1");
		}
		else if (b.second == 1)
		{
			if (arr[1].first - arr[0].first == b.first)
				printf("%d", arr[0].second);
			else if (arr[n - 1].first - arr[n - 2].first == b.first)
				printf("%d", arr[n - 1].second);
			else if (b.first == 0)
			{
				for (int i = 1; i < n; i++)
				{
					int d = arr[i].first - arr[i - 1].first;
					if (d == 0)
					{
						printf("%d", arr[i].second);
						break;
					}
				}
			}
			else
				printf("-1");
		}
		else if (a.second == 2 && a.first * 2 == b.first)
		{
			bool flag = false;
			for (int i = 2; i < n; i++)
			{
				if (arr[i].first - arr[i - 1].first == a.first && arr[i - 1].first - arr[i - 2].first == a.first)
				{
					flag = true;
					printf("%d", arr[i - 1].second);
					break;
				}
			}

			if (!flag) printf("-1");
		}
		else
			printf("-1");
	}
	else
	{
		printf("%d",arr[0].second);
	}
}