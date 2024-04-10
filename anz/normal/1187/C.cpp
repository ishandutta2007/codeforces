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

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	int order[1001]; memset(order, -1, sizeof order);

	vector <pii> o, no;
	for (int i = 0; i < m; i++)
	{
		int t, l, r; scanf("%d%d%d", &t, &l, &r);
		if (t == 1) o.push_back({ l,r });
		else no.push_back({ l,r });
	}

	for (int i = 0; i < o.size(); i++)
	{
		int l = o[i].first, r = o[i].second;
		for (int i = l; i < r; i++) order[i] = 1;
	}

	bool flag = true;

	for (int i = 0; i < no.size(); i++)
	{
		bool isChanged = false;
		int l = no[i].first, r = no[i].second;
		for (int i = l; i < r; i++)
		{
			if (order[i] != 1)
			{
				order[i] = 0;
				isChanged = true;
			}
		}
		if (!isChanged)
		{
			flag = false;
			break;
		}
	}

	if (!flag)
	{
		printf("NO");
		return 0;
	}

	printf("YES\n");

	int minNum = 1;
	vector <int> ans; ans.push_back(1);
	for (int i = 1; i < n; i++)
	{
		if (order[i] == 1) ans.push_back(ans.back() + 1);
		else
		{
			ans.push_back(ans.back() - 1);
			minNum = min(minNum, ans.back());
		}
	}

	minNum = 1 - minNum;
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d ", ans[i]+minNum);
	}
}