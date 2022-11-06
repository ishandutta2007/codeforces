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
#include <list>
#include <bitset>
#include <cmath>
#include <climits>
#include <complex>
#include <ctime>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, m;
ll a[200001];
ll cnt[1000];

ll mpow(ll a, ll n)
{
	if (n == 0) return 1;

	ll t = mpow(a, n / 2);

	t = t * t % m;
	if (n % 2)
	{
		t = t * a % m;
	}

	return t;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];

	sort(a, a + n);

	ll minusCnt = 0;

	for (int i = 0; i < n; i++)
	{
		ll tmp = 0;
		ll cm = a[i] % m;

		for (int i = cm + 1; i < m; i++) tmp += cnt[i];

		minusCnt += tmp;
		cnt[a[i] % m]++;
	}

	for (int i = 0; i < m; i++)
	{
		if (cnt[i] > 1)
		{
			cout << 0;
			return 0;
		}
	}

	ll ans = 1;
	for (int i = 0; i < m; i++) for (int j = 0; j < i; j++)
	{
		ll sub = i - j;
		ll res = mpow(sub, cnt[i] * cnt[j]);

		ans *= res;
		ans %= m;
	}

	if (minusCnt % 2 == 1)
	{
		ans = (m - ans) % m;
	}
	cout << ans;
}