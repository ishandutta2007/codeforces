#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
ll h[1000001];
ll ans[1000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	//freopen("input.txt", "r", stdin);

	cin >> n;
	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> h[i];
		sum += h[i];
	}

	ll l = 0, r = (ll)1e12 - n + 2;
	while (l + 1 < r)
	{
		ll m = (l + r) / 2;
		ll res;
		if (n % 2 == 0)
			res = (m + m + n - 1) * (n / 2);
		else
			res = (m + m + n - 1) / 2 * n;
		if (res <= sum) l = m;
		else r = m;
	}

	for (int i = 0; i < n; i++) ans[i] = l + i;

	ll tmp;
	if (n % 2 == 0)
		tmp = (l + l + n - 1) * (n / 2);
	else
		tmp = (l + l + n - 1) / 2 * n;

	ll rm = sum - tmp;

	for (int i = 0; i < rm; i++) ans[i]++;

	for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}