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

ll n, m;
ll b[100001], g[100001];
ll tmp[100001];
ll cnt[100001];
int main()
{
	scanf("%lld%lld", &n, &m);
	for (int i = 0; i < n; i++) scanf("%lld", &b[i]);
	for (int i = 0; i < m; i++) scanf("%lld", &g[i]);
	int ptr = n - 1;
	sort(b, b + n);
	sort(g, g + m);
	if (b[n - 1] > g[0])
	{
		printf("-1");
		return 0;
	}

	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans += m * b[i];

	for (int i = 0; i < m; i++)
		tmp[i] = g[i] - b[n - 1];

	for (int i = m - 1; i >= 0; i--)
	{
		if (tmp[i] == 0) break;
		if (ptr < 0)
		{
			printf("-1");
			return 0;
		}
		ans += g[i] - b[ptr];
		cnt[ptr]++;
		if (cnt[ptr] >= m - 1) ptr--;
	}

	printf("%lld", ans);
}