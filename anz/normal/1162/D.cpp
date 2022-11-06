#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}

int n, m;

vector <pii> graph;
vector <int> divi;
int cache[200001];

int b_search(pii val)
{
	int left = 0, right = m - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (val < graph[mid])
		{
			right = mid - 1;
		}
		else if (val > graph[mid])
		{
			left = mid + 1;
		}
		else return mid;
	}

	return -1;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 2; i*i <= n; i++)
	{
		if (n%i == 0)
		{
			divi.push_back(i);
			divi.push_back(n / i);
		}
	}

	divi.push_back(1);
	sort(divi.begin(), divi.end());

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (a > b) swap(a, b);
		graph.push_back({ a-1, b-1 });
	}

	sort(graph.begin(), graph.end());

	bool ans = false;
	for (int i = 0; i < divi.size(); i++)
	{
		memset(cache, -1, sizeof(cache));
		bool flag = true;
		for (int j = 0; j < graph.size(); j++)
		{
			pii tmp = graph[j];
			tmp.first = (tmp.first + divi[i]) % n;
			tmp.second = (tmp.second + divi[i]) % n;
			if (tmp.first > tmp.second) swap(tmp.first, tmp.second);

			int res = b_search(tmp);
			if (res == -1)
			{
				flag = false;
				break;
			}
			
			if (cache[res] != -1)
			{
				flag = false;
				break;
			}

			cache[res] = 1;
		}

		if (!flag) continue;

		ans = true;
		break;
	}

	if (ans) printf("Yes");
	else printf("No");
}