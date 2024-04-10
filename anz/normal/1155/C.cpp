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

ll n, m;
ll x[300001], p[300001];

ll gcd(ll a, ll b)
{
	while (b)
	{
		ll tmp = a % b;
		a = b;
		b = tmp;
	}

	return a;
}

int main()
{
	scanf("%lld%lld", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%lld", &x[i]);
	for (int i = 0; i < m; i++)
		scanf("%lld", &p[i]);

	ll g = -1;
	for (int i = 1; i < n; i++)
	{
		ll sub = x[i] - x[i - 1];
		if (g == -1)
		{
			g = sub;
		}
		else
		{
			g = gcd(g, sub);
		}
	}

	for (int i = 0; i < m; i++)
	{
		if (g % p[i] == 0)
		{
			printf("YES\n");
			printf("%lld %d", x[0], i + 1);
			return 0;
		}
	}
	printf("NO");
}