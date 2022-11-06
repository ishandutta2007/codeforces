#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
ll a[5001], b[5001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	ll mul = 0;
	for (int i = 0; i < n; i++) mul += a[i] * b[i];

	ll ans = mul;

	for (int i = 0; i < n; i++)
	{
		ll res = mul;
		for (int j = 1; 0 <= (i - j) && (i + j) < n; j++)
		{
			int l = i - j, r = i + j;
			res -= a[l] * b[l];
			res -= a[r] * b[r];
			res += a[l] * b[r];
			res += a[r] * b[l];

			ans = max(ans, res);
		}

		res = mul;
		for (int j = 0; 0 <= (i - j) && (i + 1 + j) < n; j++)
		{
			int l = i - j, r = i + 1 + j;
			res -= a[l] * b[l];
			res -= a[r] * b[r];
			res += a[l] * b[r];
			res += a[r] * b[l];

			ans = max(ans, res);
		}
	}

	cout << ans;
}