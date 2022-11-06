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
#include <bitset>
#include <climits>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
	while (b)
	{
		for (; b; a %= b, swap(a, b));
		return a;
	}
	return a;
}

int n, m;
vector <pii> candy[5001];
int pre[5001];

bool func(pii a, pii b)
{
	return (a.second - a.first + n) % n < (b.second - b.first + n) % n;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		candy[a].push_back({ a, b });
	}

	for (int i = 1; i <= n; i++)
		sort(candy[i].begin(), candy[i].end(), func);

	for (int i = 1; i <= n; i++)
	{
		if (candy[i].empty()) continue;
		pre[i] = (candy[i].size() - 1)*n;
		int dist = (candy[i].front().second - i + n) % n;
		pre[i] += dist;
	}

	for (int i = 1; i <= n; i++)
	{
		int ans = 0;
		for (int j = 1; j <= n; j++)
		{
			if (pre[j] == 0) continue;
			int dist = (j - i + n) % n;
			ans = max(ans, dist + pre[j]);
		}
		printf("%d ", ans);
	}
}