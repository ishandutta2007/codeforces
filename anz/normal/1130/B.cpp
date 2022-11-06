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

int n;
int c[2][100001];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n; i++)
	{
		int t;
		scanf("%d", &t);
		if (c[0][t] == 0) c[0][t] = i;
		else c[1][t] = i;
	}

	ll ans = 0;
	int cPos = 1;
	for (int i = 1; i <= n; i++)
	{
		ans += abs(cPos - c[0][i]);
		cPos = c[0][i];
	}

	cPos = 1;
	for (int i = 1; i <= n; i++)
	{
		ans += abs(cPos - c[1][i]);
		cPos = c[1][i];
	}

	printf("%lld", ans);
}