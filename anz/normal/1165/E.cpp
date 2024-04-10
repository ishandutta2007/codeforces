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
ll a[200001], b[200001];

const ll MOD = 998244353;

int main()
{
	ll n;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	for (ll i = 0; i < n; i++)
	{
		ll mul = (i + 1)*(n - i);
		a[i] *= mul;
	}
	sort(a, a + n);
	sort(b, b + n);

	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += ((a[i] % MOD) * (b[n - 1 - i] % MOD)) % MOD;
		ans %= MOD;
	}

	printf("%lld", ans);
}