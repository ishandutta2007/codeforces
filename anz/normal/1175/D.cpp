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

ll k, n;
ll arr[300001];

int main()
{
	priority_queue <ll> pq;
	scanf("%lld%lld", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", arr + i);
		if (i) arr[i] += arr[i - 1];
		if (i != n - 1) pq.push(-arr[i]);
	}

	ll ans = arr[n - 1] * k;
	for (int i = 0; i < k - 1; i++)
	{
		ans += pq.top();
		pq.pop();
	}

	printf("%lld", ans);
}