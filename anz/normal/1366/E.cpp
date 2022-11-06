#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll MOD = 998244353;

int n, m;
ll a[200001], b[200001];

int lb[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	if (n < m)
	{
		cout << 0;
		return 0;
	}

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	for (int i = 0; i < m; i++) lb[i] = n;

	ll ans = 1;

	bool isValid = 0;
	ll cnt = 0;
	int ptr = m - 1;

	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] < b[ptr])
		{
			if (!isValid)
			{
				ans = 0;
				break;
			}

			ans *= cnt;
			ans %= MOD;

			isValid = 0;
			cnt = 0;

			ptr--;

			if (ptr < 0 || a[i] < b[ptr]) ans = 0;
		}

		if (a[i] == b[ptr]) isValid = 1;

		if (isValid) cnt++;
	}

	if (!isValid || ptr) ans = 0;

	cout << ans;
}