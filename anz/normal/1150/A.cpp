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

int n, m, r;
int s[31], b[31];
int main()
{
	scanf("%d%d%d", &n, &m, &r);
	for (int i = 0; i < n; i++) scanf("%d", &s[i]);
	for (int i = 0; i < m; i++) scanf("%d", &b[i]);

	int minBuy = 987654321, maxSell = 0;
	for (int i = 0; i < n; i++)
		if (s[i] < minBuy) minBuy = s[i];

	for (int i = 0; i < m; i++)
		if (b[i] > maxSell) maxSell = b[i];

	if (maxSell > minBuy)
	{
		int curB = r / minBuy;
		r -= minBuy * curB;
		r += maxSell * curB;
	}

	printf("%d", r);
}