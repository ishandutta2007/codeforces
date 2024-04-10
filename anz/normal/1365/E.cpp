#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
ll a[501];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	ll ans = 0;
	if (n < 3)
	{
		for (int i = 0; i < n; i++) ans |= a[i];
		cout << ans;
		return 0;
	}

	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) for (int k = j + 1; k < n; k++)
	{
		ll res = a[i] | a[j] | a[k];
		ans = max(ans, res);
	}

	cout << ans;
}